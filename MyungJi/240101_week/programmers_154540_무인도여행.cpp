#include <bits/stdc++.h>

using namespace std;

int visited[104][104];
int dy[4]= {-1, 0, 1, 0};
int dx[4]= {0, 1, 0, -1};

int dfs(vector<string> &maps, int y, int x){
    visited[y][x]=1;
    int sum = (maps[y][x] - '0');
    for(int i=0;i<4;i++){
        int ny = y+ dy[i];
        int nx = x + dx[i];
        if (ny<0 || nx<0 || ny>=maps.size() || nx>=maps[0].size()) continue;
        if (visited[ny][nx]) continue;
        if (maps[ny][nx]!='X'){
            sum += dfs(maps, ny, nx);   
        }
    }  
    return sum;
}


vector<int> solution(vector<string> maps) {
    vector<int> answer;
    //1. dfs 수행
    for (int i=0;i<maps.size();i++){
        for(int j=0;j<maps[i].size();j++){
            if (maps[i][j]!='X' && visited[i][j]==0){
                answer.push_back(dfs(maps, i, j));
            }              
        }
    }
    if (answer.size()==0) return {-1};
    //2. 배열 정렬
    sort(answer.begin(), answer.end());
    return answer;
}