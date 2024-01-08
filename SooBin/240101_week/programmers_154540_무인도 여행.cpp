#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int arr[100][100];
bool visited[100][100];

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int M, N;

queue<pair<int, int>> q;

int bfs(int i, int j) {
    q.push({i, j});
    visited[i][j] = true;
    int cost = arr[i][j];

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && nx >= 0 && ny < M && nx < N && arr[ny][nx] != 0 && !visited[ny][nx]) {
                visited[ny][nx] = true;
                cost += arr[ny][nx];
                q.push({ny, nx});
            }
        }
    }
    return cost;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    M = maps.size();
    N = maps[0].size();

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            arr[i][j] = (maps[i][j] == 'X') ? 0 : maps[i][j] - '0';
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] != 0 && !visited[i][j]) {
                answer.push_back(bfs(i, j));
            }
        }
    }

    if (answer.empty()) {
        answer.push_back(-1);
    } else {
        sort(answer.begin(), answer.end());
    }

    return answer;
}