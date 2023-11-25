#include <bits/stdc++.h>

using namespace std;

map<string, int> mp ={{"code",0}, {"date",1}, {"maximum", 2}, {"remain", 3}};
int idx;
bool cmp(const vector<int> &a, const vector<int> &b){
    return a[idx] < b[idx];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    //1. 값 추출하기
    for (auto d: data){
        if (d[mp[ext]]<=val_ext) answer.push_back(d);
    }
    //2. 정렬하기
    idx =mp[sort_by];
    sort(answer.begin(), answer.end(), cmp);
    
    return answer;
}