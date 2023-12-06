#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll maxtime;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    //1. 최대 시간 구하기
    for (ll t:times) maxtime = std::max(t, maxtime);
    //2. 이진탐색 수행하기
    ll l=0, r=maxtime*n, mid=0;
    answer = maxtime*n; //최소 시간을 구하므로 최대 시간부터 시작
    while (l<=r){
        mid = (l+r)/2;
        ll member=0;
        for(int t:times) member += mid / t;
        if(member>=n){
            answer = min(answer, mid);
            r = mid-1;
        } else l=mid+1;
    }
    
    return answer;
}