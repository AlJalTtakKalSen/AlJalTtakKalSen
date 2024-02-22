# 도키도키 간식드리미

from collections import deque

import sys
input = sys.stdin.readline

n = int(input())
q = deque(map(int, input().split()))
stack = deque()
i = 1
while q:
    # 큐의 첫번째 값이 i이면 꺼낸 후 i 갱신
    if q and q[0] == i:
        q.popleft()
        i += 1
    # 큐의 첫번째 값이 i가 아니면
    else:
        stack.append(q.popleft())
    # 스택의 마지막 값이 i가 아닐 때까지 pop
    while stack and stack[-1] == i:
        stack.pop()
        i += 1

# 스택이 남아있다면 Sad 그렇지 않ㅇ면 Nice
if stack:
    print("Sad")
else:
    print("Nice")