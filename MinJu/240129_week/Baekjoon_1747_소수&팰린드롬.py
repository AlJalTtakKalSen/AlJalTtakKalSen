# 소수&팰린드롬

# n보다 크거나 같고, 소수이면서 팰린드롬인 수 중 가장 작은 수

n = int(input())

# 소수 판별
def is_prime(x):
    if x < 2:
        return False
    else:
        for i in range(2, int(x**0.5)+1):
            if x%i == 0:
                return False

    return True

# 팰린드롬 판별
def is_palindrome(x):
    x = str(x)
    if x == x[::-1]:
        return True
    else:
        return False

while True:
    if is_prime(n) and is_palindrome(n):
        print(n)
        break
    n += 1