import sys
input = sys.stdin.readline

N = int(input()) 
result = 0 
plus = [] # 양수
minus = [] # 음수
for _ in range(N):
    num = int(input())   
    if num == 1:         # 1일 경우 곱해도 최대 X
        result += 1
    elif num > 1:        # 양수
        plus.append(num)
    else:                # 음수
        minus.append(num)

plus.sort(reverse=True)  # 양수 오름차순
minus.sort()             # 음수 내림차순

if len(plus) % 2 == 0:   # 짝수면 2개씩 곱
    for i in range(0, len(plus), 2):
        result += plus[i] * plus[i + 1] 
else:
    for i in range(0, len(plus) - 1, 2): # 홀수일 경우 마지막 수를 제외, 2개씩 곱
        result += plus[i] * plus[i + 1]  
    result += plus[len(plus)-1]          # 마지막 수도 합산

if len(minus) % 2 == 0:  
    for i in range(0, len(minus), 2):
        result += minus[i] * minus[i + 1]
else:
    for i in range(0, len(minus) - 1, 2):
        result += minus[i] * minus[i + 1]
    result += minus[len(minus)-1]

print(result) 