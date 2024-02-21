# 순열 사이클

# 10451 순열 사이클
# 순열 -> 사이클 개수 계산
# 1부터 N까지 방문 체크 -> 방문 다음 수도 방문 X 상태이면 방문 -> 방문 시 + 1

import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000)

def dfs(k):
    visit[k] = 1     # 방문 처리
    num = arr[k]     # 다음 방문 저장
    if visit[num] == 0:  # 방문 안한 상태이면
        dfs(num)     # 재귀 호출

t = int(input())
for _ in range(t):
    n = int(input())
    arr = [0] + list(map(int, input().split()))
    visit = [0] * (n + 1)
    answer = 0  # 순열 사이클의 개수

    for i in range(1, n + 1):
        if visit[i] == 0:  # 방문 안한 상태
            dfs(i)
            answer += 1    # 사이클 개수 갱신
    print(answer)