#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000 + 1;
const int INF = INT_MAX;

vector<pair<int, int>> graph[MAX_N];

vector<int> dijkstra(int start, int N) {
    vector<int> dist(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (dist[here] < cost) continue;

        for (auto &adj : graph[here]) {
            int next = adj.first;
            int nextDist = cost + adj.second;

            if (dist[next] > nextDist) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }

    return dist;
}

int main() {
    int N, M, X;
    cin >> N >> M >> X;

    for (int i = 0; i < M; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        graph[u].push_back({v, t});
    }

    // 파티 장소에서 각 마을로 가는 최단 경로
    vector<int> toX = dijkstra(X, N);

    int longestTime = 0;
    for (int i = 1; i <= N; ++i) {
        if (i == X) continue;

        // 각 마을에서 파티 장소로 가는 최단 경로
        vector<int> toHome = dijkstra(i, N);

        // 왕복 시간 계산
        int roundTripTime = toHome[X] + toX[i];
        longestTime = max(longestTime, roundTripTime);
    }

    cout << longestTime << endl;

    return 0;
}