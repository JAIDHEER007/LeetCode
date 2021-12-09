# LC 77
# Using inbuilt functions
# https://docs.python.org/3/library/itertools.html#itertools.combinations

import itertools
def combine(n: int, k: int):
    numbers = [i for i in range(1, (n + 1))]
    return [list(seq) for seq in itertools.combinations(numbers, k)]
    
if __name__ == '__main__':
    n, k = list(map(int, input().split()))
    
    result = combine(n, k)
    
    for row in result:
        for element in row:
            print(element, end = ' ')
        print()