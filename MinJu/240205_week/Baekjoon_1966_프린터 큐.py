# 프린터 큐

from collections import deque

# 나머지 문서에 현재 문서보다 중요도가 높은 문서가 있다면 현재 문서를 큐 맨 뒤로
# 그렇지 않다면 인쇄

t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    q=deque(map(int, input().split()))
    cnt = 0

    while q:
        if q[0] == max(q): # 현재 문서가 최댓값이면 꺼내기
            q.popleft()
            cnt += 1
            if m == 0: # 찾는 문서 인쇄
                print(cnt)
                break
            else:
                m -= 1
        else: # 그렇지 않으면 뒤로 보내기
            q.append(q.popleft())
            if m == 0:
                m = len(q)-1
            else:
                m -= 1
