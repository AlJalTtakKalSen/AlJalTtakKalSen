#include <bits/stdc++.h>
using namespace std; 
int tc, n, m, w, s, e, t;
vector<pair<int, pair<int, int>>> mp;
int d[504];

bool bellmanFord(){
    for(int i=1;i<=n;i++){ 
        // 모든 간선에 대해 수행
        for(auto &e:mp){
            int from = e.first;
            int to = e.second.first;
            int cost = e.second.second;
            if (from==to && cost<0){
                return true;
            }
            if (d[to] > d[from]+cost){
                d[to] = d[from]+cost;
                if (i==n) return true;
            }
        }
    }
    return false;
}

int main(){
    //1. 입력하기
    cin >> tc;
    while (tc--){
        cin >> n >> m >> w;
        for (int i=0;i<m;i++){ // 도로의 개수
            cin >> s >> e >> t;
            mp.push_back({s, {e, t}});
            mp.push_back({e, {s, t}});
        }
        for (int i=0;i<w;i++){ // 웜홀의 개수
            cin >> s >> e >> t;
            mp.push_back({s, {e, t*(-1)}});
        }
        //2. 벨만 포드 알고리즘 수행 & 정답 출력
        if (bellmanFord()){
            cout << "YES\n";
        }
        else cout << "NO\n";
        // 3. 초기화
        fill(d, d+504, 0);
        mp.clear();
    }
    
}