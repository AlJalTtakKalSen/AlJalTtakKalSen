from collections import deque

def solution(n, wires):
    answer = 100000
    graph = [[] for _ in range(n + 1)]

    # 양쪽 모두 추가
    for a, b in wires:
        graph[a].append(b)
        graph[b].append(a)
    # 모든 노드 순회
    for a, b in wires:
        visited = [False for _ in range(n + 1)]
        q = deque()
        q.append(a)
        cnt = 1
        visited[a] = True
        visited[b] = True

        while q:
            x = q.popleft()
            for i in graph[x]:
                if not visited[i]:
                    cnt += 1
                    visited[i] = True
                    q.append(i)

        # 최솟값 최댓값 계산
        min_data = min(cnt, n - cnt)
        max_data = n - min_data
        if answer > max_data - min_data:
            answer = max_data - min_data
    return answer
