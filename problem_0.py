# Internation Collegiate Programming Contest

# November 18, 2000

# PROBLEM 2: Led Codes

# SAMPLE_INPUT = "3\nHELL1235670WO1234591561580\nPROGRAMMING037124670C123567123567156\n" \
#                "AND MORE037124903735790278134573712467045612356735792781245612467278"

ALPHABET = {
    'A': [1,2,3,4,5,7], 'B': [1,2,3,4,5,6,7],
    'C': [4,5,6], 'D': [1,5,8,0], 'E': [1,2,4,5,6],
    'F': [1,2,4,9], 'G': [1,2,5,6,9], 'H': [1,3,4,5,7],
    'I': [3,7], 'J': [3,5,6,7], 'K': [1,3,4,5,9],
    'L': [1,5,6], 'M': [1,2,3,5,7], 'N': [3,5,7,9],
    'O': [1,2,3,5,6,7], 'P': [1,4,5,8], 'Q': [1,2,3,4,7],
    'R': [1,2,3,4,5,9], 'S': [1,2,4,6,7], 'T': [2,7,8],
    'U': [1,3,5,6,7], 'V': [1,3,7,9], 'W': [1,3,5,7,9,0],
    'X': [9,0], 'Y': [1,3,4,7], 'Z': [2,3,4,5,6]
}

with open("input.txt") as file:
    lines = file.readlines()

with open("output.txt", mode="a") as file:
    for i in range(1, int(lines[0]) + 1):
        line = lines[i]
        output = ""
        j = 0
        k = 1
        while k <= len(line):
            window = line[j:k]
            if len(window) == 1:
                if 65 <= ord(window) <= 90:
                    output += window
                    j += 1
                    k += 1
                elif window == "0" or window == " ":
                    output += " "
                    j += 1
                    k += 1
                else:
                    k += 1
            else:
                window = [int(window[n]) for n in range(len(window))]
                for key, value in ALPHABET.items():
                    if list(window) == value:
                        output += key
                        j = k
                k += 1

        file.write(output + "\n")

# modularizar com funções (linhas 34, 38 - isaplhanumeric())
# inverter o hashmap e tirar o for (linha 46)
# contar tempo