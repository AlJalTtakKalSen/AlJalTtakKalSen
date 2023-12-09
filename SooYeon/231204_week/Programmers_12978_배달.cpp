#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> graph[51];
int d[2001];

void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    
    pq.push({0, start});
    d[start] = 0;
    
    while(pq.size()) {
        // 최단 거리의 정보 꺼내기
        int dist = -pq.top().first; // 비용
        int now = pq.top().second; // 노드 번호
        
        pq.pop();
        // 처리된 적 있거나 저장된 최단 거리 값보다 크면 continue
        if(dist > d[now]) continue;
        for(int i = 0; i < graph[now].size(); i++) {
            int cost = dist + graph[now][i].second;
            // 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
            if(cost < d[graph[now][i].first]) {
                d[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
        
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    for(int i = 0; i < road.size(); i++) {
        graph[road[i][0]].push_back({road[i][1], road[i][2]});
        graph[road[i][1]].push_back({road[i][0], road[i][2]});
    }
    
    fill(d, d + 2001, 987654321);
    
    dijkstra(1);

    for(int i = 1; i <= N; i++) {
        if(d[i] <= K) answer += 1;
    }

    return answer;
}
