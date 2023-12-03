# n: 대학 수, p: 강연료, d: 기한 (몇 일)
import heapq

n=int(input())
info = [list(map(int, input().split())) for _ in range(n)] # p, d
info.sort(key=lambda x: (x[1])) # d 기준 오름차순

max_p=[] # 강연료 저장

# 순회하면서 강연료 계산 
for i in info:
  heapq.heappush(max_p, i[0]) # 현재 대학의 강연료 추가 
  if (len(max_p)>i[1]):
    heapq.heappop(max_p) # 가장 작은 강연료 제거 

print(sum(max_p)) # 총 강연료