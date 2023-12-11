#include <bits/stdc++.h>
#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정

using namespace std;

// 각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열
vector<pair<int, int> > graph[51]; // 최대 50개의 마을
// 최단 거리 테이블 만들기
int d[51];


void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //내림차순 큐
    pq.push({0, start});
    d[start] = 0;
    while (!pq.empty()) {
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (d[now] < dist) continue;
        for (int i = 0; i < graph[now].size(); i++) {
            int cost = dist + graph[now][i].second;
            if (cost < d[graph[now][i].first]) {
                d[graph[now][i].first] = cost;
                pq.push({cost, graph[now][i].first});
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    // 최단 거리 테이블을 모두 무한으로 초기화
    fill(d, d + 51, INF);

    // 모든 도로 정보를 입력받아 그래프 구성
    for (int i = 0; i < road.size(); i++) {
        // 양방향 도로
        graph[road[i][0]].push_back({road[i][1], road[i][2]});
        graph[road[i][1]].push_back({road[i][0], road[i][2]});
    }

    // 다익스트라 알고리즘을 수행, 시작 노드는 1로 설정
    dijkstra(1);

    int answer = 0;
    // K 시간 이하로 배달이 가능한 마을의 수 계산
    for (int i = 1; i <= N; i++) {
        if (d[i] <= K) answer++;
    }

    return answer;
}