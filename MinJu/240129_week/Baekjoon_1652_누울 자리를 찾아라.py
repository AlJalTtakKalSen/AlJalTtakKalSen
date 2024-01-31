# 누울 자리를 찾아라

# 연속해서 2칸 빈칸 -> 누울 자리 (가로 or 세로)
# 누울 수 있는 자리의 수 (가로, 세로) 출력

import sys
input = sys.stdin.readline
n = int(input())
graph = [list(input()) for _ in range(n)]

row_cnt, col_cnt = 0, 0

for i in range(n):
    tmp_row, tmp_col = 0, 0 # 가로/세로로 누울 수 있는 자리의 길이
    for j in range(n):
        # 가로 방향 찾기
        if graph[i][j] == ".": # 빈칸이면
            tmp_row += 1 # 현재 누울 수 있는 자리 길이 +1
        else:
            tmp_row = 0
        if tmp_row == 2:
            row_cnt += 1 # 누울 수 있는 자리 카운트 +1

        # 세로 방향 찾기
        if graph[j][i] == ".":
            tmp_col += 1
        else:
            tmp_col = 0
        if tmp_col == 2:
            col_cnt += 1

print(row_cnt, col_cnt)