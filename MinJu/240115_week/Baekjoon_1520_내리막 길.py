# 내리막길
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**7)
m, n = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(m)]
visited = [[-1] * n for _ in range(m)]

def dfs(a, b):
    d = [(1,0), (-1,0), (0,1), (0,-1)]
    cnt = 0
    # 도착 지점 도달 시 1 반환
    if a == m-1 and b == n-1:
        return 1
    # 이미 방문 -> 그 위치에서 출발
    if visited[a][b] != -1:
        return visited[a][b]

    for dx, dy in d:
        nx, ny = a+dx, b+dy
        # 범위 내 + 내리막 (현재 길 < 이전 길)
        if 0 <= nx < m and 0 <= ny < n and graph[nx][ny] < graph[a][b]:
            cnt += dfs(nx, ny)
    visited[a][b] = cnt
    return visited[a][b]

print(dfs(0, 0))
