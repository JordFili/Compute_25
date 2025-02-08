import os
from random import randint

n = 10

for i in range(1, n + 1):
  number = randint(0, 99)  # Generate random number between 0 and 99
  os.system(f"./hello_number {number} > output_{i}.txt &")

os.wait()  # Wait for all background jobs to finish
