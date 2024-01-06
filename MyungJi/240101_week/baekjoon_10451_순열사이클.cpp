#include <bits/stdc++.h>
using namespace std;
int t, n, e, cnt, firstNode;
vector<int> graph[1004];
int visited[1004];

void dfs(int here){
    visited[here]=1;
    for (int node: graph[here]){
        if (!visited[node]) {
            dfs(node);
        }
    }
}
int main(){
    //1. 입력하기
    cin >> t;
    while (t--){
        cin >> n;
        for (int i=1;i<=n;i++){
            cin >> e;
            graph[i].push_back(e);
        }
        //2. dfs 수행
        for (int i=1;i<=n;i++){
            if (!visited[i]){
                firstNode = i;
                dfs(i);
                cnt++;
            }
        }
         //3. 정답 출력
        cout << cnt << "\n";
        //4. 초기화
        fill(visited, visited+1004, 0);
        for(auto &v: graph){
            v.clear();
        }
        cnt = 0;
    }   
}