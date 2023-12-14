import sys
input = sys.stdin.readline

n, w, L = map(int, input().split())    # 트럭 수, 다리 길이, 최대 하중 
data = list(map(int, input().split()))    #  n개의 트럭의 무게
bridge = [0 for _ in range(w)]    # 다리 칸 길이
count = 0                         # 최단 시간

while bridge:
    count += 1                 # 시간 카운트 
    bridge.pop(0)              # 다리 위 트럭 이동
    if data:
        if sum(bridge) + data[0] <= L:    # 현재 다리 위 트럭의 무게 + 이동하려는 트럭의 무게의 합 <= 최대 하중 
            bridge.append(data.pop(0))      # 이동 가능하므로 다리 위에 추가 
        else:                            
            bridge.append(0)             # 이동이 불가능하면 다리 위 빈 공간 추가 

print(count)   # 최단 시간