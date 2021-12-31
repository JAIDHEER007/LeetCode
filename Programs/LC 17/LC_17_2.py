# Runtime: 50ms
# Faster Than: 6.86%

# Memory Usage: 14.4MB
# Less Than: 33.17%

def letterCombinations(digits):
    if len(digits) == 0: return []

    # Letters

    letters = ["#", "#", "abc", "def", "ghi", 
               "jkl", "mno", "pqrs", "tuv", "wxyz"];

    # To store result
    combinations = []

    # Helper Function
    def findCombination(index = 0, temp = ""):
        # Base Case
        if index == len(digits):
            combinations.append(temp)
            return 

        for letter in letters[ord(digits[index]) - 48]:
            findCombination((index + 1), (temp + letter))


    findCombination()

    return combinations


if __name__ == '__main__':
    digits = input()

    combinations = letterCombinations(digits)

    for combination in combinations:
        print(combination)