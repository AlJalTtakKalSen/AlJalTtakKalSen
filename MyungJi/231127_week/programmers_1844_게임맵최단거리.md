bfs, dfs 둘 코드 두 방법으로 풀 수 있다.

## dfs
```c++
#include <bits/stdc++.h>
using namespace std;

int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
queue<pair<int,int>> q;
int visited[104][104];
int y,x,n,m;
void bfs(vector<vector<int> > &maps){
    q.push({0, 0});
    visited[0][0]=1;
    while(!q.empty()){
        tie(y,x)=q.front();
        q.pop();
        for (int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0 || nx<0 || ny>=n || nx>=m) continue;
            if (maps[ny][nx]==1 && visited[ny][nx]==0){
                q.push({ny, nx});
                visited[ny][nx] = visited[y][x]+1;
            }
        }
    }
}
int solution(vector<vector<int> > maps)
{
    int answer = 0;
    n = maps.size();
    m = maps[0].size();
    bfs(maps);
    // 정답 리턴
    answer = (visited[n-1][m-1]==0) ? -1 : visited[n-1][m-1];
    return answer;
}
```

## bfs
```c++
#include <bits/stdc++.h>

using namespace std;
int visited[204];

void bfs(int from, int n, vector<vector<int>> computers){
    queue<int> q;
    q.push(from);
    visited[from]=1;
    while(q.size()){
        int x = q.front(); q.pop();
        for (int i=0;i<n;i++){
         if(computers[x][i]==1 && visited[i]==0){
             visited[i]=1;
             q.push(i);
         }   
        }
    }
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    // 모든 정점에 대해 반복
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            visited[i]=1;
            bfs(i, n, computers);
            answer++;
        }
    }
    return answer;
}
```