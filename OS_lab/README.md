# OS Lab Notes

mkdir - make directory 
```sh
mkdir <dir_name>
```
man - fetch manual of the command
```md
man <command>
```
bc - inline calculator
```md
bc
```
chmod - change mode
```md
chmod <mode> <file_name>
```
chown - change owner
```md
chown <owner> <file_name>
```
grep - search for string
```md
grep <string> <file_name>
```
head - show first n lines
```md
head -n <n> <file_name>
```
tail - show last n lines
```md
tail -n <n> <file_name>
```



### File and Directory
touch - create file
```sh
touch <file_name>
```
cp - copy file
```sh
cp <file_name> <new_file_name>
```
mv - move file
```sh
mv <file_name> <new_file_name>
```
rm - remove file
```sh
rm <file_name>
```
rmdir - remove directory
```sh
rmdir <dir_name>
```
- read file data
```sh
read <file_name>
```

### echo - print
- print string
```md
echo <string>
```
- print string in file
```md
echo <string> > <file_name>
```
- append string in file
```md
echo <string> >> <file_name>
```
- 
```md
$echo <command>
```

### ls - show sub-folders and file 
- Display all file startign with .
```sh
ls -a 
```
- Display all file with details
```sh
ls -all
```
sh - to evalute a shell expression
```md
sh <file.sh> <expression>
```
pwd - path to directory
```sh
pwd
```
cd - change directory
```sh
cd <dir_name>
```
cat - show content of file
```md
cat <file_name>
```
```md
cat -n <filename>
```

date - show date
```md
date <format> <time_zone>
```
