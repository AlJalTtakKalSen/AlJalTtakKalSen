# 접두사
import sys
input = sys.stdin.readline
n = int(input().rstrip())
words = [input().rstrip() for _ in range(n)]

# 접두사 X 집합 : 한 단어가 다른 단어의 접두사가 되지 않는 집합
# 접두사 X 집합인 부분집합의 최대 크기 구하기

# 문자열 길이 짧은 순으로 정렬
words.sort(key=len)
answer = len(words)

for i in range(len(words)):
    # 더 긴 문자열 중에서 비교
    if any(words[i] == words[j][:len(words[i])] for j in range(i + 1, len(words))):
        answer -= 1 # 접두사가 되는 경우 제외

print(answer)
