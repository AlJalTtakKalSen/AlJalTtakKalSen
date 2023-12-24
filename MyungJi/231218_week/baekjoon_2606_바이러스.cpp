#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, cnt;
vector<int> edges[104];
int visited[104];

void dfs(int here){
    visited[here]=1;
    for(int i=0;i<edges[here].size();i++){
        int there = edges[here][i];
        if(visited[there]) continue;
        visited[there]=1;
        cnt++;
        dfs(there);
    }
}

int main(){
    // 1. 입력받기
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    //2. dfs 수행
    dfs(1);
    //3. 정답 출력
    cout << cnt;
}