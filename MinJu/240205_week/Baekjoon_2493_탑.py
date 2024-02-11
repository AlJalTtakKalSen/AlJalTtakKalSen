# 탑

n = int(input())
arr = list(map(int, input().split()))
answer = [0] * n
stack = []

# 현재 탑보다 작은 이전 탑은 스택에서 제거
# 크거나 같은 탑은 인덱스 + 1로 저장
for i in range(n-1, -1, -1):
    while stack and arr[i] > arr[stack[-1]]:
        answer[stack.pop()] = i+1
    stack.append(i)
print(*answer)