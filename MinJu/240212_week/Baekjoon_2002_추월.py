# 추월

import sys
input = sys.stdin.readline

n = int(input())
answer = 0 # 추월한 자동차 수

# 들어오는 차량 번호
in_cars = {}
for i in range(n):
    in_cars[input().strip()] = i

# 나가는 차량 번호
out_cars = []
for _ in range(n):
    out_cars.append(input().strip())

# 모든 차량 쌍에 대해 추월 여부 확인
for i in range(n - 1):
    for j in range(i + 1, n):
        # 들어오는 차량 번호를 기준으로 비교하여 추월했는지 확인
        if in_cars[out_cars[i]] > in_cars[out_cars[j]]:
            answer += 1
            break

# 추월한 자동차의 개수 출력
print(answer)

