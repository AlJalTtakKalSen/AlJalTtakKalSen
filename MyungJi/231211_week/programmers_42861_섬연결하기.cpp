#include <bits/stdc++.h>
using namespace std;
int parent[104], result;
vector<pair<int, pair<int,int>>> edges;

int findParent(int a){
    if (parent[a]==a) return a;
    return parent[a]= findParent(parent[a]);
}
void unionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);
    if (a<b) parent[b]=a;
    else parent[a]=b;
}
int solution(int n, vector<vector<int>> costs) {
    //1. 입력하기
    for(int i=1;i<=n;i++) parent[i]=i;
    for(int i=0;i<costs.size();i++){
        edges.push_back({costs[i][2], {costs[i][0], costs[i][1]}});
    }
    //2. 비용 오름차순 정렬
    sort(edges.begin(), edges.end());
    //3. 크루스칼 알고리즘 수행
    for(int i=0;i<edges.size();i++){
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        if(findParent(a) != findParent(b)){
            unionParent(a, b);
            result += cost;
        }
    }
    
    return result;
}