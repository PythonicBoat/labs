#!/bin/bash

# Verify different UNIX commands
basename --help
mkdir --help
ls --help
echo --help
read --help
expr --help
kill --help
who --help
which --help
date --help
users --help
vim --help
touch --help
bash --help
cat --help
hostname --help
rm --help
mv --help
chmod --help
top --help

# Shell program to add two numbers using command line arguments
sum=$(expr $1 + $2)
echo "Sum is: $sum"

# Shell program to convert distance into meter, cm and km
echo -n "Enter distance in cm: "
read distance
km=$(expr $distance / 100000)
mt=$(expr $distance / 100)
cm=$(expr $distance % 100)
echo "$km km $mt mt $cm cm"

# Shell script to extract the data from the date command and display in different format
formatted_date=$(date +"%e/%b/%Y/%H.%M")
echo "$formatted_date"

