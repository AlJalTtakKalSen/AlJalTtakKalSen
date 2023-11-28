#include <bits/stdc++.h>
using namespace std;
int arr[51][51];
int n, m, y, x, d, result = 0;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void dfs(int y, int x, int d) {
   if (arr[y][x] == 0) {
      arr[y][x] = 2;
      result++;
   };

   for (int i = 0; i < 4; i++) {
      // 90도 회전
      int nd = (d + 3 - i) % 4;
      int ny = y + dy[nd];
      int nx = x + dx[nd];

      if (ny >= n || nx >= m || ny < 0 || nx < 0) continue;

      if (arr[ny][nx] == 0)
         dfs(ny, nx, nd);
   }

   // 후진
   int nd = (d + 2) % 4;
   int ny = y + dy[nd];
   int nx = x + dx[nd];
   
   // 후진 했는데 벽이면
   if (arr[ny][nx] == 1) {
      cout << result << "\n";
      exit(0);
   };

   // 바라보는 방향을 유지한 채로 돌아간다.
   dfs(ny, nx, d);
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   cin >> n >> m;
   cin >> y >> x  >> d;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         cin >> arr[i][j];
      };
   };

   dfs(y, x, d);

   return 0;
}
