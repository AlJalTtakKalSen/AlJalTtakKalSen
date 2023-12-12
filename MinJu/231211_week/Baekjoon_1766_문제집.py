# 위상 정렬 
# 가능한 쉬운 문제부터 풀어야한다는 조건이 있으므로 우선순위 큐 
import heapq

n, m = map(int, input().split())
indegree = [0] * (n+1)
graph = [[] for _ in range(n+1)]
q = []

# 그래프 정보 + 진입 차수 저장
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    indegree[b] += 1 

def topology_sort():

    # 진입 차수 0인 노드를 우선순위 큐에 삽입
    for i in range(1, n + 1):
        if indegree[i] == 0:
            heapq.heappush(q, i) 
    
    # 큐가 빌 때까지 반복
    while q:
        now = heapq.heappop(q)
        print(now, end=" ")

        # 해당 원소와 연결된 노드들의 진입차수에서 1 빼기
        for i in graph[now]:
            indegree[i] -= 1
            # 진입차수가 0이 되는 노드를 큐에 삽입
            if indegree[i] == 0:
                heapq.heappush(q, i)

topology_sort()