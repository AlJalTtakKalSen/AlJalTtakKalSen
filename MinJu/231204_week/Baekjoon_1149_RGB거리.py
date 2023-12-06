# 집 N개를 빨강 초록 파랑 중 하나 색으로 칠한다.
# 조건을 만족하여 모든 집을 칠하는 최소 비용
# 1번 집 색 != 2번 집 색
# N번 집 색 != N-1번 집 색
# i번 집 색 != i-1, i+1번 집 색

import sys
input = sys.stdin.readline
n = int(input()) # 집의 수
arr = [list(map(int, input().split())) for _ in range(n)]  # 각 집마다 색칠 비용

for i in range(1, n):
        # 이전 값 중 같은 값 제외 최솟값 + 현재 빨강 칠하는 비용
    arr[i][0] = min(arr[i-1][1], arr[i-1][2]) + arr[i][0]  # 빨강
    arr[i][1] = min(arr[i-1][0], arr[i-1][2]) + arr[i][1]  # 초록
    arr[i][2] = min(arr[i-1][0], arr[i-1][1]) + arr[i][2]  # 파랑

print(min(arr[n-1])) # 최솟값