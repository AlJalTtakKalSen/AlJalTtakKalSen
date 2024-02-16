# 카드

# 카드 수 중 가장 많이 가지고 있는 수 출력 (여러 개면 가장 작은 것)

from collections import Counter
import sys
input = sys.stdin.readline

n = int(input())
nums = [int(input()) for _ in range(n)] # 카드 수 정보

nums.sort() # 정렬
num_cnt = Counter(nums) # 카드 수 개수 세기
print(num_cnt.most_common(1)[0][0])


