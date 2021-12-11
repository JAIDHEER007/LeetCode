# Lc 784
# Letter Case Permutation
# Bit Manipulation Solution

def letterCasePermutation(s):
    result = []
    
    indices = [i for i in range(len(s)) if s[i].isalpha()]
            
    n = len(indices)
    
    for i in range(0, (1 << n)):
        temp = list(s)
        j = i
        index = n - 1
        
        while j:
            if (j & 1):
                temp[indices[index]] = temp[indices[index]].swapcase()
                
            j >>= 1
            index -= 1
        
        result.append(''.join(temp))
                
         
    return result

if __name__ == '__main__':
    
    inputString = input()
    result = letterCasePermutation(inputString)
    
    for string in result:
        print(string)