#!/usr/bin/env python3

import os
import time
import requests
import argparse

import asyncio
import telnetlib3

def upload_file(file_path, url):
    try:
        with open(file_path, 'rb') as file:
            files = {'upload': file}
            response = requests.post(url, files=files)
            if response.status_code == 200:
                print("File uploaded successfully.")
            else:
                print(f"Failed to upload file. Status code: {response.status_code}")
                print(response.text)
    except Exception as e:
        print(f"An error occurred: {e}")

class TelnetClient:
    def __init__(self, host, port):
        self.host = host
        self.port = port
        self.reader = None
        self.writer = None

    async def connect(self):
        self.reader, self.writer = await telnetlib3.open_connection(self.host, self.port)
        print(f"Connected to {self.host}:{self.port}\n")

    async def send_command_and_wait_for_reply(self, command, expected_reply, timeout=30):
        if self.writer is None or self.reader is None:
            raise Exception("Not connected to the server.")

        self.writer.write(command + '\n')
        await self.writer.drain()

        response = ""
        try:
            while True:
                data = await asyncio.wait_for(self.reader.read(1024), timeout)
                if data:
                    print(data, end="") # Print each chunk as it is received
                    response += data
                    if expected_reply in response:
                        break
                else:
                    break
        except asyncio.TimeoutError:
            print("\nTimed out waiting for the expected reply.")
        
        return response

    async def close(self):
        if self.writer is not None:
            self.writer.write_eof()  # Properly send EOF
            await self.writer.drain()
            self.writer.close()
            self.reader = None
            self.writer = None
            print(f"\nDisconnected from {self.host}:{self.port}")

# Example usage
async def main():
    host = 'fluidnc.local'
    port = 23
    client = TelnetClient(host, port)

    await client.connect()

    try:

        if not args.nohome or args.home:
            print("Homing...")
            await client.send_command_and_wait_for_reply("$H", "ok")

        if args.file_path != None:
            print("Reporting on...")
            await client.send_command_and_wait_for_reply("$Report/Interval=1000", "ok")

            print("Running job...")
            await client.send_command_and_wait_for_reply("$SD/Run=/" + os.path.basename(file_path) , "succeeded", 5)

        if args.md:
            print("Disabling motors...")
            await client.send_command_and_wait_for_reply("$MD", "ok")

    finally:
        await client.close()

if __name__ == "__main__":
    
    parser = argparse.ArgumentParser(description="Upload a file and run it.")
    parser.add_argument("file_path", nargs='?', help="Path to the file to upload")
    parser.add_argument("--noupload", action="store_true", help="Choose not to upload the file (if it has already been uploaded)")
    parser.add_argument("--nohome", action="store_true", help="Choose not to home")
    parser.add_argument("--home", action="store_true", help="Home the machine (default when uploading files)")
    parser.add_argument("--md", action="store_true", help="Disable motors")

    args = parser.parse_args()

    file_path = args.file_path
    url = "http://fluidnc.local/upload"
    
    if not args.noupload and args.file_path != None:
        upload_file(file_path, url)    
    
    asyncio.run(main())
