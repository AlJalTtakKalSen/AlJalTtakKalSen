from collections import deque

# bfs 수행 
def solution(maps):
    
    answer = 0
    n = len(maps)
    m = len(maps[0])
    
    # 이동할 방향 정의 (상하좌우)
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    
    q = deque()
    q.append((0, 0)) # 큐 시작점
    
    while q: # 큐가 빌 때까지 반복 
        x, y = q.popleft()
        
        for i in range(4): # 상하좌우 확인
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < m and maps[nx][ny] == 1: # 범위 내이고 처음 방문
                maps[nx][ny] = maps[x][y] + 1
                q.append((nx, ny))
    answer = maps[n-1][m-1] # 상대 팀 진영까지 거리 (가장 오른쪽 아래)         
    
    if answer == 1: # 상대 팀 진영에 도착할 수 없는 경우 -1 반환 
        answer = -1
    
    return answer