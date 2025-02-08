#!/bin/bash

# Program 1: Write a shell script to create folders determined by input
echo "Please enter a number: "
read num

if [ "$num" -gt 0 ]; then
  echo "$num is positive"
  echo "Creating $num folders..."
  
  for ((i = 1; i <= num; i++)); do
    mkdir "Folder_$i"
    echo "Folder_$i created"
  done
  
elif [ "$num" -lt 0 ]; then
  echo "$num is negative"
else
  echo "$num is zero"
fi