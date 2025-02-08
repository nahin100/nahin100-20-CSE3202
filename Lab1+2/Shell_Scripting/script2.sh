#!/bin/bash

num=$1  # Assign the first argument to num

# Program 1: Check if the number is positive, negative, or zero
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