def knuthMorrisPrattAlgorithm(string, substring):
    pattern = buildPattern(substring)
    return KMPsearch(string, substring, pattern)


def buildPattern(substring):
    pattern = [-1 for _ in substring]
    i, j = 1, 0

    while i < len(substring):
        if substring[i] == substring[j]:
            pattern[i] = j
            i += 1
            j += 1

        elif j > 0:
            j = pattern[j - 1] + 1

        else:
            i += 1

    return pattern


def KMPsearch(string, substring, pattern):
    i, j = 0, 0

    while i + len(substring) - j <= len(string):
        if string[i] == substring[j]:
            if j == len(substring) - 1:
                return True

            i += 1
            j += 1

        elif j > 0:
            j = pattern[j - 1] + 1

        else:
            i += 1

    return False


print(knuthMorrisPrattAlgorithm("ababcabcabababd", "ababd"))

# References:
# 1. https://www.algoexpert.io/questions/Knuth%E2%80%94Morris%E2%80%94Pratt%20Algorithm
# 2. https://www.youtube.com/watch?v=V5-7GzOfADQ
# 3. https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
