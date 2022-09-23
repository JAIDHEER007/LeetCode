import enum
from fileinput import filename
import os
from os.path import join
import sys
import pyperclip

# Currrent Working Directory
cwd = sys.path[0]

# Directory for snippet codes
scDir = join(cwd, "codes")

# Getting all files in snippte codes
files = os.listdir(scDir)

print("Code Snipptes Available")
for (i, fileName) in enumerate(files, start = 0):
    print("{fileNum} ==> {fileName}".format(fileNum = i, fileName = fileName))

opt = int(input("Enter the desired file number: "))

if opt >= len(files):
    print("Enter a Valid Option. Try Again!!")
else:
    try:
        with open(join(scDir, files[opt]), 'r') as fileHandle:
            fileContents = fileHandle.readlines()
            joinedFC = ''.join(fileContents)

            print("\nFile Contents are:")
            print(joinedFC)

            pyperclip.copy(joinedFC.replace('"', '\\"').replace('\n', '\\n'))
    except Exception as exp:
        print(exp)
        print("Try Again!!")
    