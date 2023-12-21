#include <bits/stdc++.h>

using namespace std;
// 끝점 기준으로 오름차순 정렬
bool cmp(vector<int> v1, vector<int> v2){
    return v1[1] < v2[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    //1. 끝점 기준으로 정렬하기
    sort(targets.begin(), targets.end(), cmp);
    //2. 시작점이 요격 위치보다 큰 경우에 미사일 발사
    double lastIntercept=-1;
    for(vector<int> target:targets){
        if(lastIntercept<target[0]){
            lastIntercept = target[1]-0.1;
            answer++;
        }
    }
    //3. 정답 출력
    return answer;
}