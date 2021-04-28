# tools to calculate runtime and memory consumption
from guppy import hpy
import psutil, os
from time import time

hp = hpy()
hp.setrelheap()

# dictionaries that will keep track of the letter counting
gentec = {'A': [], 'B': [], 'C': [], 'D': [], 'E': [], 'F': [], 'G': [], 'H': [], 'I': [], 'J': [], 'K': [], 'L': [], 'M': [], 'N': [], 'O': [], 'P': [], 'Q': [], 'R': [], 'S': [], 'T': []}
genco = {'a': [], 'b': [], 'c': [], 'd': [], 'e': [], 'f': [], 'g': [], 'h': [], 'i': [], 'j': [], 'k': [], 'l': [], 'm': [], 'n': [], 'o': [], 'p': [], 'q': [], 'r': [], 's': [], 't': []}
letter_mapping = {'A': '?', 'B': '?', 'C': '?', 'D': '?', 'E': '?', 'F': '?', 'G': '?', 'H': '?', 'I': '?', 'J': '?', 'K': '?', 'L': '?', 'M': '?', 'N': '?', 'O': '?', 'P': '?', 'Q': '?', 'R': '?', 'S': '?', 'T': '?'}


def get_input(file_path: str) -> list:      # open input file and get a list of all the lines
    with open(file_path) as file:
        content = file.readlines()

    return content


def save_output(file_path: str, content: str):
    with open(file_path, mode="a") as file:
        file.write(content)


def parse_content(content: list) -> dict:
    test_cases = {}
    for line in content:
        line = line.strip("\n")
        if line.isnumeric():                # if line content is a number, then it's
            num_subjects = int(line)        # the number of individuals being tested (subjects)

            if num_subjects == 0:           # if the number is zero, it's the end of file
                break

            test_cases.update({num_subjects: []})   # creates a key-value pair that maps the number of subjects to a
        else:                                       # list with coded genes of each company
            subjects = line.split(" ")
            test_cases[num_subjects].append(subjects)   # appends subjects' coded genes in the respective list

    return test_cases


def compare_groups(company_a: dict, company_b: dict) -> dict:
    mapping = {}
    for group_a, letters_a in company_a.items():
        for group_b, letters_b in company_b.items():
            matches = 0
            for letter_a, indexes_a in letters_a.items():
                for letter_b, indexes_b in letters_b.items():

                    if indexes_a == indexes_b:  # if there's a match, don't continue to compare to other letters
                        matches += 1            # (may count more matches than there really are if there are several
                        break                   # letters with coinciding indexes)

            if matches == len(letters_a):
                mapping.update({group_a: group_b})  # if all letters match, map group_a to group_b

    return mapping


def compare_letters(group_a: dict, group_b: dict):  # there's A LOT of redundancy, but i couldn't figure out how to map
    global letter_mapping                           # letters before mapping groups, because it's the only way
                                                    # (i could think) it'll be always correct
    for letter_a, indexes_a in group_a.items():
        for letter_b, indexes_b in group_b.items():
            if indexes_a == indexes_b:
                letter_mapping[letter_a] = letter_b
                break


def group(data: dict) -> dict:          # group genes ('ABCDE', 'FGHIJ', etc)
    output = {i: {} for i in range(4)}  # obs.: i didn't group the genes before to facilitate the gene counting
    count = 0
    i = 0
    for key, value in data.items():
        if len(value) > 0:                  # exclude empty lists for optimization
            output[i].update({key: value})
        count += 1
        if count == 5:
            count = 0
            i += 1

    return output


# ------------ SOLUTION ------------- #
def main():
    global gentec, genco, letter_mapping      # needed to solve namespace problems

    raw_data = get_input("combin.in")
    data = parse_content(raw_data)
    test_counter = 1

    for num_subjects, genes_list in data.items():   # loop through each test case

        for letter, indexes in gentec.items():   # count genes in GenTec database
            for i in range(num_subjects):
                if letter in genes_list[0][i]:
                    indexes.append(i)

        for letter, indexes in genco.items():    # count genes in GenCo database
            for i in range(num_subjects):
                if letter in genes_list[1][i]:
                    indexes.append(i)

        gentec_grouped = group(gentec)      # group genes
        genco_grouped = group(genco)

        group_mapping = compare_groups(gentec_grouped, genco_grouped)   # maps corresponding groups

        for key, value in group_mapping.items():
            compare_letters(gentec_grouped[key], genco_grouped[value])  # maps corresponding letters

        output = f"Test #{test_counter}:\n"
        for key, value in letter_mapping.items():   # format output string
            output += f"{key}-{value} "
            if key in 'EJOT':
                output += '\n'

        save_output("combin.out", output)       # save output string to file

        test_counter += 1       # reset counters and letter mapping to solve next test case
        gentec = {'A': [], 'B': [], 'C': [], 'D': [], 'E': [], 'F': [], 'G': [], 'H': [], 'I': [], 'J': [], 'K': [], 'L': [], 'M': [], 'N': [], 'O': [], 'P': [], 'Q': [], 'R': [], 'S': [], 'T': []}     
        genco = {'a': [], 'b': [], 'c': [], 'd': [], 'e': [], 'f': [], 'g': [], 'h': [], 'i': [], 'j': [], 'k': [], 'l': [], 'm': [], 'n': [], 'o': [], 'p': [], 'q': [], 'r': [], 's': [], 't': []}
        letter_mapping = {'A': '?', 'B': '?', 'C': '?', 'D': '?', 'E': '?', 'F': '?', 'G': '?', 'H': '?', 'I': '?', 'J': '?', 'K': '?', 'L': '?', 'M': '?', 'N': '?', 'O': '?', 'P': '?', 'Q': '?', 'R': '?', 'S': '?', 'T': '?'}


if __name__ == '__main__':
    before = time()

    main()  # run the solution

    after = time()
    print(after - before)
    h = hp.heap()
    print(h)
    process = psutil.Process(os.getpid())
    print('Used memory (in bytes): ' + str(process.memory_info().rss))
