# 올림픽

n, k = map(int, input().split())
medals = [list(map(int, input().split())) for _ in range(n)]
medals.sort(key=lambda x: (x[1],x[2],x[3]), reverse=True) # 금은동 많은 순

for i in range(n):
    if medals[i][0] == k:
        idx = i # 해당 국가 인덱스
for i in range(n):
    if medals[i][1:] == medals[idx][1:]:
        print(i+1)
        break