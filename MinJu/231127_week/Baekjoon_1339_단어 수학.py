# N개의 단어, 각 단어는 알파벳 대문자로 구성 -> 0부터 9까지 숫자 중 하나로 바꾸어
# N개의 수 합 최대

N = int(input()) # 단어 수
words = list(input() for _ in range(N)) # 단어 입력
alpha = list([0] * 26) # 각 알파벳 자릿값 합
result = 0

# 각 단어의 알파벳에 자릿값 더하기 
for word in words:
    digit = 1
    for k in reversed(word):
        alpha[ord(k) - ord('A')] += digit
        digit *= 10

alpha.sort(reverse=True)

# 최댓값 할당하기 
for i in range(10):
    if alpha[i] == 0:
        break
    result += alpha[i] * (9-i)

print(result)