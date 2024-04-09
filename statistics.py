# for this to work best, there must have the same number of words in nouns.txt
# and adjectives.txt AND you should printf the index of the word (variable r)
# instead of the username itself in the .c file

import subprocess
import time

data = {}

while isinstance(1/2, float):
    output = subprocess.getoutput("./generate")
    for i in output.split():
        if i in data.keys():
            data[i] += 1
        else:
            data[i] = 1
    print(output)
    with open("stats.txt", "w") as file:
        file.write(str(data))
    time.sleep(0.9)
