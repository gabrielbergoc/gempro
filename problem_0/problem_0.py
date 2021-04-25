# Internation Collegiate Programming Contest
# November 18, 2000
# PROBLEM 2: Led Codes

# SAMPLE_INPUT = "3\nHELL1235670WO1234591561580\nPROGRAMMING037124670C123567123567156\n" \
#                "AND MORE037124903735790278134573712467045612356735792781245612467278"

# to track memory usage
from guppy import hpy
hp = hpy()
hp.setrelheap()

import psutil, os

# to calculate runtime
from time import time
before = time()

# hash table coded letter -> decoded letter
ALPHABET = {
    '123457': 'A',
    '1234567': 'B',
    '456': 'C',
    '1580': 'D',
    '12456': 'E',
    '1249': 'F',
    '12569': 'G',
    '13457': 'H',
    '37': 'I',
    '3567': 'J',
    '13459': 'K',
    '156': 'L',
    '12357': 'M',
    '3579': 'N',
    '123567': 'O',
    '1458': 'P',
    '12347': 'Q',
    '123459': 'R',
    '12467': 'S',
    '278': 'T',
    '13567': 'U',
    '1379': 'V',
    '135790': 'W',
    '90': 'X',
    '1347': 'Y',
    '23456': 'Z'
}

# auxiliary function
def is_space(string: str):
    if string == "0" or string == " ":
        return True
    return False

# read input file
with open("input.txt") as file:
    lines = file.readlines()    # this function reads the file and returns a list with all the lines in the file

# open output file
with open("output.txt", mode="a") as file:

    # main loop: begins at line 1 and ends at the line specified in line 0
    for i in range(1, int(lines[0]) + 1):
        line = lines[i]     # saves current line to variable "line"
        output = ""         # creates empty string to save decoded line
        j = 0               # initializes index j
        k = 1               # initializes index k - these indexes will save the current substring being decoded (window)

        while k <= len(line):   # loop responsible for scanning the line - stops when the window reaches the end of line
            window = line[j:k]  # saves current window to a variable (for ease of reading and debugging)

            if len(window) == 1:    # no coded letter has length 1, so when window has length 1,
                                    # only checks for decoded letters and spaces

                if window.isalpha():    # checks for letters
                    output += window    # if true, appends window to the end of the output string
                    j += 1
                    k += 1  # moves whole window

                elif is_space(window):  # checks for spaces (zeros or literal spaces)
                    output += " "       # if true, appends window to the end of the output string
                    j += 1
                    k += 1  # moves whole window
                else:
                    k += 1  # if current window isn't a letter or space, widens window
            else:
                if window in ALPHABET.keys():   # checks if current window has a match in alphabet keys
                    output += ALPHABET[window]  # if so, appends decoded letter to the end of the output string
                    j = k   # moves window past the already decoded letter
                k += 1      # widens window

        file.write(f"Phrase {i}: " + output + "\n")   # appends decoded line to the end of file


after = time()
print(after - before)   # print runtime

# print memory usage
h = hp.heap()
print(h)

# print memory usage
process = psutil.Process(os.getpid())
print('Used memory (in bytes): ' + str(process.memory_info().rss))