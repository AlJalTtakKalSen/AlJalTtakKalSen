import heapq
import sys
input = sys.stdin.readline
n = int(input())
arr = []
for _ in range(n):
    heapq.heappush(arr, int(input()))
result = 0

while len(arr) > 1:
    first = heapq.heappop(arr)  
    second = heapq.heappop(arr)  
    result += first + second
    heapq.heappush(arr, first + second)
print(result)
