# lab 3

eq - equal

ne - not equal

lt - less than

le - less than or equal to

gt - greater than

ge - greater than or equal to

```sh
if [$a eq $b]
then
    echo "a is equal to b"
fi
```
## File flags

- `-f` - file exists and is a regular file
- `-d` - file exists and is a directory
- `-e` - file exists
- `-r` - file is readable
- `-w` - file is writable


echo "Enter a number:"
read number

# Check if the number is even or odd
if (( number % 2 == 0 ))
then
    echo "$number is even"
else
    echo "$number is odd"
fi

