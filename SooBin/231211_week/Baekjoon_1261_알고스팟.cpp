#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

int N, M;

char graph[101][101];
int d[101][101];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int bfs() {
    deque<pair<int,int>> dq;
    dq.push_back({1,1});
    while (!dq.empty()) {
        int y = dq.front().first;
        int x = dq.front().second;
        dq.pop_front();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny > N || nx > M || ny < 1 || nx < 1) continue;
            if (d[ny][nx] != INF) continue;

            if (graph[ny][nx] == '0') {
                dq.push_front({ ny,nx });
                d[ny][nx] = d[y][x];
            }
            if (graph[ny][nx] == '1'){
                dq.push_back({ ny,nx });
                d[ny][nx] = d[y][x] + 1;
            }
        }
    }
    return d[M][N];
}

int main() {

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (i == 1 && j == 1) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }

    int answer = bfs();

    cout << answer;

    return 0;
}