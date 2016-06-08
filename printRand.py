import random

file = open("randomNumbers.txt", "w")

for i in range(0, 1000000):
    file.write(str(random.randrange(-1000000, 1000000))+" ")

file.close()
