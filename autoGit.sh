#!/bin/bash

# Read the file path
echo Enter Relative file path?
read -r fpath

# Extract the direcotry / file name from the file path
name=$(basename "$fpath")

# Use the name to create the commit message
commitMsg="Added $name"

# echo $name
# echo $commitMsg

git init
git add "$fpath"
git status 
git commit -m "$commitMsg"
git pull origin main 
git push origin main 
git status 