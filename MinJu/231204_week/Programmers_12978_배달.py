from heapq import heappop, heappush

def solution(N, road, K):
    answer = 0
    distance = [1e9] * (N+1)  # 각 마을까지의 최단 거리를 저장, 초기값은 무한대 
    graph = [[] for _ in range(N+1)]  # 각 마을과 연결된 도로 정보를 담은 인접 리스트

    # 그래프 정보 설정
    for a, b, c in road:
        graph[a].append((b, c))
        graph[b].append((a, c))

    distance[1] = 0  # 자신 -> 자신의 거리는 0

    # 우선순위 큐를 사용한 다익스트라 알고리즘
    min_heap = [(0, 1)]  # (거리, 노드)

    while min_heap:
        dist, node = heappop(min_heap)

        if distance[node] < dist:
            continue  # 이미 더 짧은 경로가 들어가있다면 건너뛰기 

        for next_node, next_dist in graph[node]:
            new_dist = dist + next_dist
            if distance[next_node] > new_dist:
                distance[next_node] = new_dist
                heappush(min_heap, (new_dist, next_node))  # 더 짧은 거리이면 우선순위 큐에 추가

    #  K 이하인 거리의 마을 개수 세기
    for new_dist in distance[1:]:
        if new_dist <= K:
            answer += 1

    return answer
