#!/bin/bash

# Read the file path
# echo Enter Relative file path?
# read -r fpath

# fpath = $1

# Extract the direcotry / file name from the file path
# echo "$1"

name=$(basename "$1")

# Use the name to create the commit message
commitMsg="Added $name"

# echo $name
# echo $commitMsg

git init
git add "$1"
git status 
git commit -m "$commitMsg"
git pull origin main 
git push origin main 
git status 