# 좋다

# 어떤 수가 다른수 두개의 합으로 나타낼 수 있는 경우 좋은 수


import sys
input = sys.stdin.readline

n = int(input())
nums = list(map(int, input().split()))
nums.sort()
answer = 0 # 좋은 수 개수

for i in range(n):
    tmp = nums[:i] + nums[i+1:] # i번째 수 제외한 리스트
    start, end = 0, n-2

    while start < end:
        case = tmp[start] + tmp[end] # 두 수의 합 조합
        # 표현 가능하면 카운트
        if case == nums[i]:
            answer += 1
            break
        # 아닐 경우 시작, 끝 조정
        elif case < nums[i]:
            start += 1
        else:
            end -= 1
print(answer)