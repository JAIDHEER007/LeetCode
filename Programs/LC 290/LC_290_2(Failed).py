# Failed for the test case
# "abc" 
# "b c a"

# As a single dictionary is used to store 
# the token and pattern they will be overwritten 
# Just analyze it 
# Unlike C/C++ there is no char datatype in python
# Just STRING of Length 1

def wordPattern(pattern, s):
    i = 0
    pn = len(pattern)

    table = {}

    for token in s.split():
        if i == pn: return False

        if token not in table:
            if pattern[i] not in table:
                table[token] = pattern[i]
                table[pattern[i]] = token
            else: return False
        else: 
            if table[token] != pattern[i]: return False

        i += 1

    return (i == pn)
    

if __name__ == '__main__':
    pattern = input()
    s = input()

    print(wordPattern(pattern, s))