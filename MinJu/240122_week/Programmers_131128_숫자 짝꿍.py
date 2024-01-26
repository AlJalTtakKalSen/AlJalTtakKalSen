# 숫자 짝꿍

# 두 정수의 공통 정수로 만들 수 있는 가장 큰 정수 구하기
from collections import Counter
def solution(X, Y):
    answer = ''
    nums = Counter(X) & Counter(Y)
    print(nums)
    if not nums:
        return "-1"
    elif list(nums) == ['0']:
        return "0"
    sort_nums = sorted(list(nums), reverse=True)
    for i in sort_nums:
        answer += i*nums[i]
    return answer