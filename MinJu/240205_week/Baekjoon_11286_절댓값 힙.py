# 절댓값 힙

import heapq
import sys
input = sys.stdin.readline
# 절댓값 힙 : 절댓값이 가장 작은 값 출력하여 제거

n = int(input())
min_heap = []
max_heap = []

for _ in range(n):
    x = int(input())
    # 양수이면 최소 힙에 저장
    if x > 0:
        heapq.heappush(min_heap, x)
    # 음수이면 최대 힙에 저장
    elif x < 0:
        heapq.heappush(max_heap, -x)
    # 0인 경우
    else:
        # 두 힙 모두 값이 존재할 경우 더 작은 값 출력
        if min_heap and max_heap:
            if min_heap[0] < max_heap[0]:
                print(heapq.heappop(min_heap))
            else:
                print(-heapq.heappop(max_heap))
        # 최소힙만 존재
        elif min_heap:
            print(heapq.heappop(min_heap))
        # 최대힙만 존재
        elif max_heap:
            print(-heapq.heappop(max_heap))
        # 둘 다 존재하지 않을 경우
        else:
            print(0)



