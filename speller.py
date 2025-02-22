from time import time

#Words in a dictionary
words = set()

def check(word):
    """Return true if word is in dictionary, else false"""
    return word.lower() in words


def load(dictionary):
    """Load dictionary into memory, returning true if successful else false"""
    with open(dictionary) as file:
        words.update(file.read().splitlines())  #file.read reads everything as one big blob, splitlines will split on a new line char
        return True


def size():
    """Returns number of words in dictionary or 0 if not loaded"""
    return len(words)


def unload():
    return True     #Garbage collection is amazing


if __name__ == "__main__":
    from sys import argv
    if len(argv) != 3:
        print("Usage: python speller.py <dictionary> <file-to-check>")
    else:
        start = time()
        misspelled = 0
        dictionary = argv[1]
        file_to_check = argv[2]
        if load(dictionary):
            print(f"Loaded {size()} words...")
        else:
            print("UNABLE TO LOAD DICTIONARY")

        with open(file_to_check) as f:
            # TODO read all the words
            for line in f.readlines():
                for word in line.splitlines():
                    #word = word.replace(".", ""), would need to use this to remove punctuation
                    if not check(word):
                        misspelled +=1

        unload() #not necessary!
        end = time()

        print(f"{file_to_check} has {misspelled} misspelled words.")
        elapsed = round(end - start, 2)
        print(f"Finished in {elapsed} seconds.")


