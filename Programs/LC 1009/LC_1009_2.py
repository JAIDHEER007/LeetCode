def bitwiseComplement(num):
    if num == 0: return 1 

    result = 0
    i = 0
    while num:
        bit = (num % 2) ^ 1; 
        result += (bit * (1 << i));

        num //= 2; 
        i += 1; 

    return result


if __name__ == '__main__':
    num = int(input())

    print(bitwiseComplement(num))