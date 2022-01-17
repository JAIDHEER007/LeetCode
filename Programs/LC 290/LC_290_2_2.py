# Runtime: 32ms
# Faster Than: 64.43%
# Memory Usage: 14.2 MB
# Less Than: 80.26%

def wordPattern(pattern, s):
    i = 0
    pn = len(pattern)

    table = {}

    for token in s.split():
        if i == pn: return False

        patternOrd = ord(pattern[i])

        if token not in table:
            if patternOrd not in table:
                table[token] = patternOrd
                table[patternOrd] = token
            else: return False
        else: 
            if table[token] != patternOrd: return False

        i += 1

    return (i == pn)
    

if __name__ == '__main__':
    pattern = input()
    s = input()

    print(wordPattern(pattern, s))