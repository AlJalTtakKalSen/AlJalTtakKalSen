# 적록색약
# 같은 색상 상하좌우 인접 -> 같은 구역
# 적록색약인 사람은 빨간색 = 초록색
# 적록색약인 사람과 아닌 사람이 봤을 때 구역의 수 각각 구하가ㅣ

from collections import deque
import sys
sys.setrecursionlimit(100000)
input = sys.stdin.readline

n = int(input())
graph = [list(input()) for _ in range(n)]

def bfs(x, y, visited):
    q = deque()
    q.append((x, y))
    visited[x][y] = True
    # 이동 방향 (상하좌우)
    d = [(1,0), (-1,0), (0,1), (0,-1)]

    while q:
        x, y = q.popleft()
        for dx, dy in d:
            nx, ny = x+dx, y+dy
            # 범위 내 + 방문 X
            if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny]:
                # 색이 같으면 같은 구역
                if graph[nx][ny] == graph[x][y]:
                    q.append((nx, ny))
                    bfs(nx, ny, visited)

# 적록색약이 아닌 경우 구역 수 구하기
visited1 = [[False] * n for _ in range(n)]
cnt1 = 0
for i in range(n):
    for j in range(n):
        if not visited1[i][j]:
            bfs(i, j, visited1)
            cnt1 += 1

# 적록색약인 경우 구역 수 구하기
# 초록=빨강
for i in range(n):
    for j in range(n):
        if graph[i][j] == 'G':
            graph[i][j] = 'R'
visited2 = [[False] * n for _ in range(n)]
cnt2 = 0
for i in range(n):
    for j in range(n):
        if not visited2[i][j]:
            bfs(i, j, visited2)
            cnt2 += 1
print(cnt1, cnt2)
