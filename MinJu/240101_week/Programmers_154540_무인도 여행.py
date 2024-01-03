from collections import deque

def solution(maps):
    answer = []
    # 범위
    n = len(maps)  # 세로
    m = len(maps[0])  # 가로
    visited = [[0] * m for _ in range(n)]  # 방문 여부

    # 상하좌우 방향
    d = [(0, 1), (0, -1), (1, 0), (-1, 0)]

    for i in range(n):
        for j in range(m):
            # 바다이거나 이미 방문한 곳이면 무시
            if maps[i][j] == 'X' or visited[i][j]:
                continue

            q = deque()
            q.append((i, j))
            visited[i][j] = 1

            day = 0

            while q:
                x, y = q.popleft()
                day += int(maps[x][y])

                for dx, dy in d:
                    nx, ny = x + dx, y + dy
                    # 범위 내에 있고, 바다가 아니며, 방문하지 않은 경우
                    if 0 <= nx < n and 0 <= ny < m and maps[nx][ny] != 'X' and not visited[nx][ny]:
                        visited[nx][ny] = 1
                        q.append((nx, ny))

            # 최대 며칠 동안 머무를 수 있는지를 리스트에 추가
            if day:
                answer.append(day)

    # 최종적으로 answer 리스트 반환
    if answer:
        answer.sort()
        return answer
    else:
        return [-1]
