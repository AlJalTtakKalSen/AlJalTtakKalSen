#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, cnt;
string s;
int mp[1004][1004];
int visited[1004][1004][2]; // y x cnt
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

void bfs(){
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    visited[0][0][0]=1;
    while(!q.empty()){
        tie(y, x, cnt) = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny<0||nx<0||ny>=n||nx>=m) continue;
            if (mp[ny][nx]==0 && visited[ny][nx][cnt]==0){
                visited[ny][nx][cnt] = visited[y][x][cnt]+1;
                q.push({ny, nx, cnt});
            } 
            // 벽 부시기
            if(mp[ny][nx]==1 && cnt==0 && visited[ny][nx][1]==0){
                visited[ny][nx][1] = visited[y][x][cnt]+1;
                q.push({ny, nx, 1});
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    // 1. 입력받기
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> s;
        for(int j=0;j<m;j++){
            mp[i][j] = s[j]-'0';
        }
    }
    // 2. bfs 수행
    bfs();
    // 3. 정답 출력
    int ans1 = visited[n-1][m-1][0];
    int ans2 = visited[n-1][m-1][1];
    if(ans1==0 && ans2==0) cout << -1;
    else if (ans1==0) cout << ans2;
    else if (ans2==0) cout << ans1;
    else cout << min(ans1, ans2); 
}

