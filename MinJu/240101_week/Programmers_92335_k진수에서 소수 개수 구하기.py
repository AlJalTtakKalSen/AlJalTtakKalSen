# k진수에서 소수 개수 구하기

# 소수 판별
def is_prime(num):
    if num < 2:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def solution(n, k):
    word = ""
    # n을 k진수로 변환
    while n:
        word = str(n % k) + word
        n = n // k

    word = word.split("0")

    # 소수 개수 찾기
    answer = 0
    for w in word:
        if len(w) > 0 and int(w) > 1 and is_prime(int(w)):
            answer += 1

    return answer
