#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> tree[10004];
int n, a, b, c, maxDistance, farthestNode;
int visited[10004];

void dfs(int node, int distance){
    visited[node]=1;
    if (distance > maxDistance){
        maxDistance = distance;
        farthestNode = node;
    }
    for (auto &p: tree[node]){
        if (visited[p.first]) continue;
        dfs(p.first, distance+p.second);
    }
}
int main(){
    //1. 입력받기
    cin >> n;
    for (int i=0;i<n-1;i++){
        cin >> a>> b>> c;
        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }
    //2. 가장 끝 노드 구하기
    dfs(1, 0);
    //3. 초기화
    fill(visited, visited+10004, 0);
    maxDistance = 0;
    //4. leaf 노드에서 dfs 수행
    dfs(farthestNode, 0);
    //3. 정답 출력
    cout << maxDistance;
}