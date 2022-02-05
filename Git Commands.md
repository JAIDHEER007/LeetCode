## Git commands

* ```git init```
<br>Initalizing git

* ```git add . ```
<br>adding the changes to temporary space

* ```git commit -m "message" ```
<br>commit with a message

* ```git pull origin main```
<br>adding the changes to temporary space

* ```git push origin main```
<br>pushing the changes to main branch

* ```git status -s | sed s/^...// | xargs grep -l "Enter Test Case Here" | sed 's/^/"/;s/$/"/' | xargs rm && git add . ```

* This command deletes any input text files which are unused<br>
**Working:**<br>
* ```git status -s```  Returns the added files with status and path 
* ```sed s/^...//```  Removes the status and returns only the path
* ```xargs grep -l "Enter Test Case Here"``` Checks every file for ```Enter Test Case Here``` phrase and returns the file path without Quotations
* ```sed 's/^/"/;s/$/"/'```  Adding Quotations at first and last place of the string
* ```xargs rm && git add .```  Remove the unused items and readd the files
