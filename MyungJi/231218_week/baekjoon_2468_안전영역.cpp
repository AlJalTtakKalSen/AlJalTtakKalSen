#include <bits/stdc++.h>

using namespace std;
int n, temp, maxH, answer;
int mp[104][104], visited[104][104];
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
void dfs(int y, int x, int h){
    visited[y][x]=1;
    for(int i=0;i<4;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny<0||nx<0||ny>=n||nx>=n) continue;
        if (visited[ny][nx]) continue;
        if (mp[ny][nx]>h){
            dfs(ny, nx, h);
        }
    }
}
int main(void) {
    // 1. 입력받기
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> temp;
            mp[i][j] = temp;
            maxH = max(maxH, temp);
        }
    }
    //2. dfs 수행
    for (int h=0;h<=maxH;h++){
        int ret=0;
        fill(&visited[0][0], &visited[0][0]+104*104, 0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (mp[i][j]>h && visited[i][j]==0){
                    dfs(i, j, h);
                    ret++;
                }
            }
        }

        answer = max(answer, ret);
    }
    //3. 정답 출력
    cout << answer;
}