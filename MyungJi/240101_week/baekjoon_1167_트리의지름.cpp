#include <bits/stdc++.h>
using namespace std;
int v, n, a, b, farthestNode, maxDistance;
vector<pair<int, int>> tree[100004];
int visited[100004];

void dfs(int node, int distance){
    if (distance > maxDistance){
        maxDistance = distance;
        farthestNode = node;
    }
    visited[node] = 1;
    for (auto &p : tree[node]){
        if (visited[p.first]) continue;
        dfs(p.first, distance + p.second);
    }
}


int main(){
    //1. 입력받기
    cin >> v;
    for(int i=0;i<v;i++){
        cin >> n;
        while(true){
            cin >> a;
            if (a==-1) break;
            cin >> b;
            tree[n].push_back({a, b});
        }
    }
    // 2. 가장 긴 노드 찾기
    dfs(1, 0);
    // 3. 가장 긴 노드로 최대 거리 = 트리의 지름 구하기
    maxDistance = 0;
    fill(visited, visited+100004, 0);
    dfs(farthestNode, 0);
    //4. 정답 출력하기
    cout << maxDistance;
}