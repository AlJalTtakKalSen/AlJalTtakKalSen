#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define INF 999999

using namespace std;

int N, M;
int array[300][300] = {0};
bool visited[300][300] = {false};

int dy[4] = {0,0,1,-1};
int dx[4] = { 1,-1,0,0 };

queue<pair<int, int>> q;
queue<pair<int, int>> waterQ;

int day = 0;

void connect() {

	while (!q.empty()) {

		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int a = 0; a < 4; a++) {
			int ny = y + dy[a];
			int nx = x + dx[a];

			if (ny >= 0 && nx >= 0 && ny < N && nx < M && ::array[ny][nx] >= 1 && !visited[ny][nx]) {
				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}

	}
}

void reset() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = false;
		}
	}
}

void day1() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (::array[i][j] == 0) {
				waterQ.push(make_pair(i, j));
			}
		}
	}
	while (!waterQ.empty()) {
		int y = waterQ.front().first;
		int x = waterQ.front().second;
		waterQ.pop();
		for (int a = 0; a < 4; a++) {
			int ny = y + dy[a];
			int nx = x + dx[a];

			if (ny >= 0 && nx >= 0 && ny < N && nx < M && ::array[ny][nx] >= 1 ) {
				::array[ny][nx] -= 1;
			}
		}
	}
}

bool isAllMelt() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (::array[i][j] != 0) return false;
		}
	}
	return true;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> ::array[i][j];
        }
    }
    


	while (!isAllMelt()) {
		reset();

		int count = 0;

		// 빙산 개수 확인
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (::array[i][j] >= 1 && !visited[i][j]) {
					count++;
					visited[i][j] = true;
					q.push(make_pair(i, j));
					connect();
				}
			}
		}


		if (count >= 2) {
			cout << day;
			return 0;
		}


		day1();
		day++;
	}

	cout << 0;
    return 0;
}