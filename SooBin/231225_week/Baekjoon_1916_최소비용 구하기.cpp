#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

vector<pair<int, int>> graph[1001];
long long d[1001];

void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    pq.push({ 0,start });   
    d[start] = 0;
    while (!pq.empty()) {
        long long dist = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // !
        if (d[node] < dist) continue;

        for (unsigned int i = 0; i < graph[node].size(); i++) {
            long long cost = dist + graph[node][i].second;

            // !
            if (cost < d[graph[node][i].first]) {
                d[graph[node][i].first] = cost;
                pq.push({ -cost,graph[node][i].first });
            }
        }

    }
}

int main() {
    
    int N, M;
    cin >> N >> M;

    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({ b,c });
    }

    int A, B;
    cin >> A >> B;

 
    fill(d, d + 1001, LLONG_MAX);
    dijkstra(A);

    cout << d[B];  return 0;
}

  