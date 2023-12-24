#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
vector<int> graph[100004];
int indegree[32004];
vector<int> result;
// 위상 정렬
void topologySort(){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=1;i<=n;i++){
        if (indegree[i]==0) pq.push(i);
    }
    while(!pq.empty()){
        int now = pq.top();
        pq.pop();
        result.push_back(now);
        for(int i=0;i<graph[now].size();i++){
            int node = graph[now][i];
            indegree[node]-=1;
            if(indegree[node]==0) pq.push(node);
        }

    }
}

int main(){
    // 1. 입력받기
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b] += 1;
    }
    // 2. 위상정렬
    topologySort();
    // 3. 결과 출력
    for(int r:result) cout << r << " ";
}