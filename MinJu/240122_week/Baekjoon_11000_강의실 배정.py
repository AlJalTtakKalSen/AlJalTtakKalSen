# 강의실 배정

import heapq
import sys
input = sys.stdin.readline

n = int(input())
info = []
for _ in range(n):
    info.append(list(map(int, input().split())))
info.sort()

answer = []
heapq.heappush(answer, info[0][1])

for i in range(1, n):
    # 다음 회의 시작시간이 현재 회의 종료시간보다 빠르면 새 회의실 필요
    if info[i][0] < answer[0]:
        heapq.heappush(answer, info[i][1])
    # 현재 회의실에 이어서 가능하면 시간 업데이트
    else:
        heapq.heappop(answer)
        heapq.heappush(answer, info[i][1])
print(len(answer)) # 최소 강의실 개수