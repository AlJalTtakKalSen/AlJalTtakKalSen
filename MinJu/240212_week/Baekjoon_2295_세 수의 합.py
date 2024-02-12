# 세 수의 합

import sys
input=sys.stdin.readline

n=int(input())
u=set()
answer=[]

for i in range(n):
    u.add(int(input()))

cases =set() # 두 수의 합 x+y
for i in u:
    for j in u:
        cases.add(i + j)

# 세 수의 합이 두 수의 합에 포함되는지 확인
for i in u:
    for j in u:
        if (i-j) in cases:
            answer.append(i)

answer.sort()
print(answer[-1]) # 가장 큰 수