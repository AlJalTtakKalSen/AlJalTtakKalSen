# n : 섬의 개수 
# costs : 섬 사이 다리 건설 비용 정보 ( 섬 번호 1, 섬 번호 2, 건설 비용)

# 크루스컬 알고리즘 

# 루트 노드 찾을 때까지 재귀 호출 (경로 압축)
def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]

# 합집합 연산
def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b
        
def solution(n, costs):
    answer = 0
    parent = [i for i in range(n)] # 부모 테이블 초기화 
    costs.sort(key=lambda x: x[2]) # 간선을 비용순으로 정렬
    
    for edge in costs:
        a, b, cost = edge 
        # 두 노드가 같은 집합에 속하지 않는 경우 -> 합집합 연산 + 비용 누적 
        if find_parent(parent, a) != find_parent(parent, b):
            union_parent(parent, a, b)
            answer += cost 
    
    return answer