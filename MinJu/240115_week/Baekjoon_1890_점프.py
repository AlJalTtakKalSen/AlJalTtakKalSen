# 점프

# 가장 오른쪽 아래칸으로 이동하는 경로의 개수
# 오른쪽, 아래쪽으로만 이동 가능
# 각 칸의 수는 현재 칸에서 갈 수 있는 거리

import sys
input = sys.stdin.readline

n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]
dp = [[0] * n for _ in range(n)]

dp[0][0] = 1 # 시작점

# 이동할 수 있는 좌표 탐색
for i in range(n):
    for j in range(n):
        # 최종 도착지면 종료
        if i == n-1 and j == n-1:
            break
        # 오른쪽 이동
        if j + board[i][j] < n:
            dp[i][j+board[i][j]] += dp[i][j]
        # 아래쪽 이동
        if i + board[i][j] < n:
            dp[i+board[i][j]][j] += dp[i][j]
print(dp[n-1][n-1])