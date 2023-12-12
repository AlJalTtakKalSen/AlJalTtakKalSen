import sys
input = sys.stdin.readline

# 최소 신장 트리 성질 
# 길이 없어 왕복 시에는 같은 종류의 비행기 -> N - 1 
T = int(input())  # 테스트 케이스 수 
for _ in range(T):
    N, M = map(int, input().split()) # 국가 수, 비행기 종류 수 
    for _ in range(M):
        a, b = map(int, input().split())
    print(N-1)
