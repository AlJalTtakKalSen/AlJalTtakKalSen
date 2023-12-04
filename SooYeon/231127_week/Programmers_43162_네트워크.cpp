#include <bits/stdc++.h>
using namespace std;
int visited[201] = {0,};
vector<vector<int>> vv;

void dfs(int start) {
    visited[start+1] = 1;
    // 해당 노드에 대해 연결되어 있는 노드들을 모두 dfs로 확인
    for(int i = 0; i < vv[start].size(); i++) {
        // 만약 자기 노드라면 continue
        if(vv[start][i] == start+1) continue;
        // 방문했던 노드라면 continue
        if(visited[vv[start][i]]) continue;
        dfs(vv[start][i]-1);
    };
};

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<int> v;
    // 각 노드에 대해 연결된 노드를 vector에 저장
    for(int i = 0; i < computers.size(); i++) {
        for(int j = 0; j < computers[i].size(); j++) {
            if(computers[j][i]) {
                v.push_back(j+1);
            };
        };
        vv.push_back(v);
        v.clear();
    };
    
    // 방문하지 않은 노드에 대해 dfs 호출
    for(int i = 0; i < computers.size(); i++) {
        if(visited[i+1]) continue;
        answer++;
        dfs(i);
    };
    
    return answer;
}
