# 차집합

import sys
input = sys.stdin.readline

n, m = map(int, input().split())
a = set(map(int, input().split()))
b = set(map(int, input().split()))

# 차집합
answer = list(a - b)
answer.sort()

print(len(answer)) # 차집합의 크기
print(*answer) # 차집합의 원소
