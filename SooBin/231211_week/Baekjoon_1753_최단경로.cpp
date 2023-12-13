#include <iostream>
#include <vector>
#include <queue>

#define INF 999999

using namespace std;

// V=정점의 개수, E=간선의 개수, K=시작 정점의 번호
int V, E, K;
// 각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열
vector<pair<int, int>> graph[20001];
// 방문한 적이 있는지 체크하는 목적의 배열
bool visited[20001];
// 최단 거리 테이블
int d[20001];

// 다익스트라 알고리즘
void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    // 시작 노드로 가기 위한 최단 경로는 0으로 설정하여 큐에 삽입
    pq.push({0, start});
    d[start] = 0;
    while (!pq.empty()) {
        int dist = -pq.top().first; // 현재 노드까지의 비용
        int now = pq.top().second;  // 현재 노드
        pq.pop();
        // 현재 노드가 이미 처리된 적이 있는 노드라면 무시
        if (d[now] < dist) continue;
        // 현재 노드와 연결된 다른 인접한 노드들을 확인
        for (int i = 0; i < graph[now].size(); i++) {
            // 여기서 second는 큐의 second가 아닌 graph의 second이다.
            // gragh는 출발노드, 도착노드, 비용 순
            int cost = dist + graph[now][i].second;
            // 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우 갱신, 큐에 삽입
            if (cost < d[graph[now][i].first]) {
                d[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
    }
}


int main() {
 
    cin >> V >> E >> K;

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        // a노드에서 b노드로 가는 비용은 c이다.
        graph[a].push_back({ b,c });
    }

    // 최단 거리 테이블을 모두 무한으로 초기화
    fill(d, d + 20001, INF);
    dijkstra(K);

    for(int i = 1; i <= V; i++){
        if (d[i] == INF) {
            cout << "INF\n";
        }
        else {
            cout << d[i] << '\n';
        }
    }


    return 0;
}