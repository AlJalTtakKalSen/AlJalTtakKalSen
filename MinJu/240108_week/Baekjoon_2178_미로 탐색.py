# 미로 탐색
# 1 : 이동 가능 0 : 이동 불가능
# (1,1) -> (N,M) 최소 칸 수 구하기
from collections import deque
n, m = map(int, input().split())
arr = [list(map(int, input().rstrip())) for _ in range(n)]

q = deque()
q.append((0, 0)) # 0,0에서 시작

d = [(1,0), (-1,0), (0,1), (0,-1)]
while q:
    x, y = q.popleft()
    for dx, dy in d:
        nx, ny = x+dx, y+dy
        # 범위 내 + 이동 가능
        if 0 <= nx < n and 0 <= ny < m and arr[nx][ny] == 1:
            q.append((nx, ny))
            arr[nx][ny] = arr[x][y] + 1 # 이동한 칸 수 저장
answer = arr[n-1][m-1]
print(answer)