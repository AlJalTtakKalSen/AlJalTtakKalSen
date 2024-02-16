# 접두사 찾기

import sys
input = sys.stdin.readline

n, m = map(int, input().split())
s = [input().strip() for _ in range(n)] # 집합 s 문자열
t = [input().strip() for _ in range(m)] # 검사해야하는 문자열

# 집합 s 중 하나이상의 접두사인 것 개수 구하기

s.sort() # 사전순 정렬
answer = 0
for i in t:
    left, right = 0, n-1
    flag = False
    while left <= right:
        mid = (left+right)//2
        # 접두사인 경우 (t에 있는 문자열로 시작)
        if s[mid].startswith(i):
            flag = True
            break
        elif s[mid] < i: # i보다 사전순으로 앞에 있는 경우
            left = mid + 1
        else: # i보다 사전순으로 뒤에 있는 경우
            right = mid - 1
    # 접두사인 경우 개수 카운트
    if flag:
        answer += 1
print(answer)