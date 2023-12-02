#include <bits/stdc++.h>

using namespace std;
// map<char, int> mp;
vector<int> v(104, 0);

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    //1. 문자 map 생성
    for (int i=0;i<keymap.size();i++){
        for(int j=0;j<keymap[i].size();j++){
            char c = keymap[i][j];
            if(v[c]==0) v[c]=j+1;
            else v[c]=min(j+1, v[c]);   
        }
    }
    //2. target 생성
    for(int i=0;i<targets.size();i++){
        int ret=0;
        for(int j=0;j<targets[i].size();j++){
            int num = v[targets[i][j]];
            if (num==0){
                ret=-1;
                break;
            } 
            else ret += num;
        }
        answer.push_back(ret);
    }
    return answer;
}