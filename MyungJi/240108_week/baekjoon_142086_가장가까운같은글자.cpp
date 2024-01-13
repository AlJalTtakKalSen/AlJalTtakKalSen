#include <bits/stdc++.h>

using namespace std;
map<char, int> mp;
int idx;
vector<int> solution(string s) {
    vector<int> answer;
    for (int i=0;i<s.length();i++){
        char c = s[i];
        if (mp.find(c) ==mp.end()){
            mp[c]=i;
            answer.push_back(-1);
        } else{
            int step = i-(mp[c]);
            mp[c]=i; // 최신으로 업데이트
            answer.push_back(step);
        } 
    }
    return answer;
}

// 처음 나온 글자이면 인덱스 저장, -1 출력
// 존재하는 글자이면 인덱스 반환