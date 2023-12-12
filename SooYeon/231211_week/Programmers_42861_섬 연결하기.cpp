#include <bits/stdc++.h>
using namespace std;
int parent[101];
vector<pair<int, pair<int, int>>> edges;

int findParent(int x) {
    if(x == parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    
    for(int i = 0; i < costs.size(); i++) {
        edges.push_back({costs[i][2], {costs[i][0], costs[i][1]}});
    }
    
    sort(edges.begin(), edges.end());
    
    for(int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        
        if(findParent(a) != findParent(b)) {
            unionParent(a, b);
            answer += cost;
        }
    }
    
    return answer;
}
