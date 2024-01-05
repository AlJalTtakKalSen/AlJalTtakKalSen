#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> tree[100004];
bool visited[100004];
int farthestNode = 0;
int maxDistance = 0;

void dfs(int node, int distance) {
    visited[node] = true;
    if (distance > maxDistance) {
        maxDistance = distance;
        farthestNode = node;
    }
    for (auto &p : tree[node]) {
        if (!visited[p.first]) {
            dfs(p.first, distance + p.second);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int v, x, a, b;
    cin >> v;
    for (int i = 0; i < v; ++i) {
        cin >> x;
        while (true) {
            cin >> a;
            if (a == -1) break;
            cin >> b;
            tree[x].push_back({a, b});
        }
    }

    // 첫 번째 DFS 실행
    dfs(1, 0);
    
    // 방문 기록 초기화
    fill(visited, visited + v + 1, false);
    maxDistance = 0;

    // 두 번째 DFS 실행
    dfs(farthestNode, 0);

    cout << maxDistance << '\n';
    return 0;
}