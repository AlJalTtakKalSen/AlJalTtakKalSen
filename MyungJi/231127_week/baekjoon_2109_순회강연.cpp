#include <bits/stdc++.h>
using namespace std;
int n, d,p, ret;
vector<pair<int, int>> v;
priority_queue<int> pq;
int main(){
    //1. 입력받기
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> p >> d;
        v.push_back({d, p});
    }
    //2. 내림차순 정렬
    sort(v.begin(), v.end(), greater<>()); 
    //3. 우선순위 큐에 집어넣기
    int ptr=0;
    if (!v.empty()){
        for(int i=v[0].first;i>=1;i--){ // 날짜 큰 순 -> 작은 순
            while(ptr<n && v[ptr].first>=i) pq.push(v[ptr++].second);
            if(pq.size()){
                ret += pq.top(); pq.pop();
            }
        }    
    }
    cout << ret;
}