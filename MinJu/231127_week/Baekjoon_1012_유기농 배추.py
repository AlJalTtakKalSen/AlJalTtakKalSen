# 유기농 배추
# 1은 배추 심어진 땅 0은 안심어진 땅
# 흰지렁이 상하좌우 인접 이동
# 필요한 최소 흰지렁이 수 구하기 
from collections import deque

# bfs 함수 정의
def bfs(graph, i, j):

    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]

    q = deque()
    q.append((i, j))

    graph[i][j] = 0 # 현위치 

    # bfs 탐색
    while q:
        x, y = q.popleft()

        # 상하좌우 이동
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            # 이동한 위치가 범위 안인지 확인
            if 0 <= nx < n and 0 <= ny < m:
                # 이동한 위치가 1이면
                if graph[nx][ny] == 1:
                    # 해당 위치를 0으로 저장하고 큐에 추가
                    graph[nx][ny] = 0
                    q.append((nx, ny))
    return


T = int(input())
for _ in range(T):
    # 배추밭의 가로길이, 세로길이, 배추 위치 개수 입력
    n, m, k = map(int, input().split())

    # 배추밭
    graph = [[0] * m for _ in range(n)]

    # 배추 위치는 1로 표시
    for _ in range(k):
        x, y = map(int, input().split())
        graph[x][y] = 1

    result = 0  # 필요한  최소 흰지렁이 수 

    # 모든 위치에 대해 탐색
    for i in range(n):
        for j in range(m):
            # 배추가 심어져 있는 경우, 해당 배추 위치에서 bfs 수행
            if graph[i][j] == 1:
                bfs(graph, i, j)
                result += 1

    print(result)