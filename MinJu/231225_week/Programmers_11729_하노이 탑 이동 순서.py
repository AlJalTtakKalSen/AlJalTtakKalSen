# 하노이 탑 이동 순서

n = int(input()) # 원판의 개수

# 세 개의 장대
# 1. 한 번에 한 개의 원판 이동 가능
# 2. 큰 원판이 작은 원판 위에 있을 수 없음
# 이동 순서 출력 (최소)

def solution(n, start, end):
    if n == 1:
        print(start, end)
    else:
        solution(n-1, start, 6-start-end) # 1 -> 2
        print(start, end) # 1 -> 3
        solution(n-1, 6-start-end, end) # 2 -> 3

print(2**n - 1) # 옮긴 횟수 k
solution(n, 1, 3)
