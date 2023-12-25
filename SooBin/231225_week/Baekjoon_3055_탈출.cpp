#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define INF 999999

using namespace std;

int R, C;

char array[50][50];
bool visited[50][50];

int dy[4] = {0,0,1,-1};
int dx[4] = { 1,-1,0,0 };

void spreadWater(queue<pair<int, int>>& waterQ) {
	int waterSize = waterQ.size();

	for (int i = 0; i < waterSize; i++) {
		int y = waterQ.front().first;
		int x = waterQ.front().second;
		waterQ.pop();

		for (int a = 0; a < 4; a++) {
			int ny = y + dy[a];
			int nx = x + dx[a];

			if (ny >= 0 && nx >= 0 && ny < R && nx < C && ::array[ny][nx] == '.') {
				::array[ny][nx] = '*';
				waterQ.push({ ny, nx });
			}
		}
	}
}


int main() {
    cin >> R >> C;

    int startY, startX, endY, endX;

    queue<pair<int, int>> waterQ;
    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> ::array[i][j];
            visited[i][j] = false;

            if (::array[i][j] == 'S') {
                startY = i;
                startX = j;
            }
            else if (::array[i][j] == 'D') {
                endY = i;
                endX = j;
            }
            else if (::array[i][j] == '*') {
                waterQ.push({ i, j });
            }
        }
    }

    q.push({ {startY, startX}, 0 });
    visited[startY][startX] = true;

    while (!q.empty()) {
        spreadWater(waterQ);

        int size = q.size();

        for (int b = 0; b < size; b++) {
            int y = q.front().first.first;
            int x = q.front().first.second;
            int day = q.front().second;
            q.pop();

            if (y == endY && x == endX) {
                cout << day;
                return 0;
            }

            for (int a = 0; a < 4; a++) {
                int ny = y + dy[a];
                int nx = x + dx[a];

                if (ny >= 0 && nx >= 0 && ny < R && nx < C && !visited[ny][nx] && ::array[ny][nx] != '*' && ::array[ny][nx] != 'X') {
                    visited[ny][nx] = true;
                    q.push({ {ny, nx}, day + 1 });
                }
            }
        }
    }

    cout << "KAKTUS";
    return 0;
}