# 다익스트라 풀이
```c++
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
```
# 플로이드-워셜 풀이
```c++
#include <bits/stdc++.h>
#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정

using namespace std;

// 노드의 개수(N), 간선의 개수(M)
// 노드의 개수는 최대 500개라고 가정
int n, m;
// 2차원 배열(그래프 표현)를 만들기
int graph[501][501];

int main(void) {
    cin >> n >> m;

    // 최단 거리 테이블을 모두 무한으로 초기화
    fill(&graph[0][0], &graph[0][0]+51*51, INF);


    // 자기 자신에서 자기 자신으로 가는 비용은 0으로 초기화
    for (int a = 1; a <= n; a++) {
        graph[a][a] = 0;
    }

    // 각 간선에 대한 정보를 입력 받아, 그 값으로 초기화
    for (int i = 0; i < m; i++) {
        // A에서 B로 가는 비용은 C라고 설정
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
    }
    
    // 점화식에 따라 플로이드 워셜 알고리즘을 수행
    for (int k = 1; k <= n; k++) {
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
            }
        }
    }

    // 수행된 결과를 출력
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            // 도달할 수 없는 경우, 무한(INFINITY)이라고 출력
            if (graph[a][b] == INF) {
                cout << "INFINITY" << ' ';
            }
            // 도달할 수 있는 경우 거리를 출력
            else {
                cout << graph[a][b] << ' ';
            }
        }
        cout << '\n';
    }
}
```