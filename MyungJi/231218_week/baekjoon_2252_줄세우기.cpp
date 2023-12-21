#include <bits/stdc++.h>
using namespace std;

int n, m, a, b; 
int indegree[32004];
vector<int> graph[100004];
vector<int> result;

void topologySort(){
    queue<int> q;
    // 진입차수가 0인 노드 큐에 집어넣기
    for(int i=1;i<=n;i++){
        if(indegree[i]==0) q.push(i);
    }
    // 큐가 빌때까지 반복
    while(!q.empty()){
        int now = q.front();
        q.pop();
        result.push_back(now);
        for(int i=0;i<graph[now].size();i++){
            int node = graph[now][i];
            indegree[node]-=1;
            if(indegree[node]==0) q.push(node);
        }
    }
}

int main(){
    //1. 입력받기
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]+=1;
    }
    // 2. 위상정렬 수행
    topologySort(); 
    //  3. 정답 출력
    for(int r:result) cout << r << " ";
}