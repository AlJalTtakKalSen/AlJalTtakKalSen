# 집합의 표현

# 0....n - n+1개의 집합
# 합집합 연산, 두 원소가 같은 집합에 포함인지 확인하는 연산 수행

import sys
sys.setrecursionlimit(1000000) # 재귀 깊이 제한 늘리기
input = sys.stdin.readline

n, m = map(int, input().split())
parent = [i for i in range(n+1)] # 부모 테이블

# 찾기 연산
def find_parent(x):
    if parent[x] != x:
        parent[x] = find_parent(parent[x])
    return parent[x]

# 합집합 연산
def union_parent(a, b):
    a = find_parent(a)
    b = find_parent(b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

# 각 집합 연산 수행
# 0 a b : a가 포함된 집합과 b가 포함된 집합 합치기
# 1 a b : a와 b가 같은 집합에 포함되어 있는지 확인
for _ in range(m):
    k, a, b = map(int, input().split())
    if k == 0: # 합집합
        union_parent(a, b)
    else:
        if find_parent(a) == find_parent(b):
            print('YES')
        else:
            print('NO')