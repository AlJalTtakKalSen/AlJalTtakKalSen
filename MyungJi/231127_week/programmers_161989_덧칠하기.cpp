#include <bits/stdc++.h>

using namespace std;
bool colored[100004];

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    //1. section 시작점부터 m칸 색칠
    for(int i=0;i<section.size();i++){
        int start = section[i];
        if (colored[start]==1) continue;
        for(int j=start;j<min(start+m, n+1);j++){
            colored[j]=true;  
        } 
        answer++;
    }
    return answer;
}