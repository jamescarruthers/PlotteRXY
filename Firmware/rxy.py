#!/usr/bin/env python3

import os
import time
import requests
import telnetlib
import argparse

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

    tn = telnetlib.Telnet("fluidnc.local", 23, 5)
    
    if not args.nohome or args.home:
        print("Homing... ")
        try:
            tn.write("$H".encode('ascii') + b"\n")
            # response = tn.read_until("ok".encode('ascii')).decode('ascii')
            # print(response)
            while True:
                response = tn.expect([b'\n'], 30)
                if response:
                    reply = response[2]
                    if reply == b"ok\r\n":
                        print(reply.decode('ascii'), end="")
                        break
                    print(reply.decode('ascii'), end="")
                else:
                    time.sleep(1)  # Sleep briefly to avoid tight loop
        except EOFError:
            print("\nTelnet connection closed by server")
        except Exception as e:
            print(f"An error occurred while connecting to Telnet: {e}")
    
    if args.file_path != None:
    
        print("Turn on reporting...")
        tn.write("$Report/Interval=1000".encode('ascii') + b"\n")
        
        print("Running job...")
        command = "$SD/Run=/" + os.path.basename(file_path)
        
        try:
            tn.write(command.encode('ascii') + b"\n")
            # response = tn.read_until("ok".encode('ascii')).decode('ascii')
            # print(response)
            while True:
                response = tn.expect([b'\n'], 30)
                if response:
                    reply = response[2]
                    if reply == b"ok\r\n":
                        print(reply.decode('ascii'), end="")
                        break
                    print(reply.decode('ascii'), end="")
                else:
                    time.sleep(1)  # Sleep briefly to avoid tight loop
            
            print("Starting...")
            
            while True:
                response = tn.expect([b'\n'], 30)
                if response:
                    reply = response[2]
                    if b"MSG" in reply:
                        print(reply.decode('ascii'), end="")
                        break
                    print(reply.decode('ascii'), end="")
                else:
                    time.sleep(1)  # Sleep briefly to avoid tight loop

        except EOFError:
            print("\nTelnet connection closed by server")
        except Exception as e:
            print(f"An error occurred while connecting to Telnet: {e}")

    if args.md:
        command = "$MD"
        tn.write(command.encode('ascii') + b"\n")

    tn.close()
