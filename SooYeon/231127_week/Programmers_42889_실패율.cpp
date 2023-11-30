#include <bits/stdc++.h>
using namespace std;
int total_people = 0;

bool compare(pair<int, double> a, pair<int, double> b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
};

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> v;
    int stage[200001] = {0,};
    
    total_people = stages.size();
    
    for(int i = 0; i < stages.size(); i++) {
        stage[stages[i]]++;
    };
    
    for(int i = 1; i <= N; i++) {
        // 0에서 다른값으로 나누게 되면 가끔 0이 안나올때까 있음 컴퓨터 소수점
        if(stage[i] == 0) {
            v.push_back({i, 0});
            continue;
        };
        v.push_back({i, stage[i]/(double)total_people});
        total_people -= stage[i];
    };
    
    sort(v.begin(), v.end(), compare);
    
    for(int i = 0; i < v.size(); i++)
        answer.push_back(v[i].first);
    
    return answer;
}