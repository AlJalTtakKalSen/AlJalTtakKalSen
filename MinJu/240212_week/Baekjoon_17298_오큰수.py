# 오큰수

# i보다 오른쪽 + i보다 큰 수 중 가장 왼쪽에 있는 수
# 없으면 -1

import sys
input = sys.stdin.readline

n = int(input()) # 수열 A 크기
arr = list(map(int, input().split())) # 수열 A

answer = [-1] * n # 오큰수 저장

stack = [] # 인덱스 저장
for i in range(n):
    # 오큰수 찾기
    while stack and arr[i] > arr[stack[-1]]:
        answer[stack.pop()] = arr[i] # 해당 수 저장
    stack.append(i)
print(*answer)
