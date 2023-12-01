#include<bits/stdc++.h>
using namespace std;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int visited[101][101] = {0,};

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size(), m = maps[0].size();
    
    queue<pair<int, int>> q;
    q.push({0,0});
    visited[0][0] = 1;
    
    while(q.size()) {
        int y, x;
        tie(y, x) = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny >= n || nx >= m || ny < 0 || nx < 0) continue;
            if(visited[ny][nx] || !maps[ny][nx]) continue;
            
            q.push({ny, nx});
            visited[ny][nx] = visited[y][x] + 1;
        };
    };
    
    if(visited[n-1][m-1] == 0) return -1;
    answer = visited[n-1][m-1];
    
    return answer;
}
