#!/bin/bash

n=10

for i in $(seq 1 $n); do
  number=$((RANDOM % 100))  # Generate random number between 0 and 99
  ./hello_number $number > "output_$i.txt" &  # Run in background
done

wait  # Wait for all background jobs to finish