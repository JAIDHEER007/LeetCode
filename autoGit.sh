#!/bin/bash

echo Enter Relative file path?
read -r fpath

name=$(basename "$fpath")
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