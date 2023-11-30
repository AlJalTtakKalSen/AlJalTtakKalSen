#include <bits/stdc++.h>

using namespace std;
int visited[204];

void dfs(int from, int n, vector<vector<int>> computers){
    for(int i=0;i<n;i++){
        if (from!=i && computers[from][i]==1 && visited[i]==0){
            visited[i]=1;
            dfs(i, n, computers);
        }
    }

}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<n;i++){
        if(visited[i]==1) continue;
        visited[i]=1;
        dfs(i, n, computers);
        answer++;
    }
    
    return answer;
}