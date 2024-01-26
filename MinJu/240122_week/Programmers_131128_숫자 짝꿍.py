# 숫자 짝꿍

# 두 정수의 공통 정수로 만들 수 있는 가장 큰 정수 구하기
from collections import Counter

def solution(X, Y):
    answer = ''
    nums = Counter(X) & Counter(Y)
    print(nums)
    # 짝꿍이 없는 경우
    if not nums:
        return "-1"
    # 짝꿍이 0밖에 없는 경우
    elif list(nums) == ['0']:
        return "0"
    # 숫자 큰 순으로 정리
    order = sorted(list(nums), reverse=True)
    # 위 순서대로 정수 만들기 + 같은 정수 Counter 수 고려
    for i in order:
        answer += i*nums[i]
    return answer