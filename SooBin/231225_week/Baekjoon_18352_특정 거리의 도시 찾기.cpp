#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define INF 999999

using namespace std;

void dijkstra(vector<vector<int>>& graph, int start, vector<int>& distance) {
    int n = graph.size();

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int current = pq.top().second;
        int current_distance = pq.top().first;
        pq.pop();

        for (const int& edge : graph[current]) {
            int to = edge;
            int weight = 1;

            if (current_distance + weight < distance[to]) {
                distance[to] = current_distance + weight;
                pq.push({ distance[to], to });
            }
        }
    }
}

int main() {
    int N, M, K, X;
    cin >> N >> M >> K >> X;
    
    vector<vector<int>> graph(N);

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        graph[A-1].push_back(B-1);
    }

    vector<int> distance(N, INF);

    dijkstra(graph, X - 1, distance);

    bool flag = true;
    for (int i = 0; i < N; i++) {
        if (distance[i] == K) {
            cout << i + 1 << endl;
            flag = false;

        }
    }
    if (flag) {
        cout << -1;
    }

    return 0;
}