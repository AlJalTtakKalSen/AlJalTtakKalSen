#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> copy_relation;
vector<vector<int>> complete_key_v;

void combi(int start, vector<int> b, int k) {
    if(b.size() == k) {
        // 후보키로 사용할 수 있는지 확인
        // 1. 미리 찾은 후보키들 중 포함되는게 없어야 함
        // 2. 모든 row가 같은게 없어야 함
        int cnt = 0;
        bool found = false;
        for(vector<int> v: complete_key_v) {
            cnt = 0;
            for(int col: b) {
                if(find(v.begin(), v.end(), col) != v.end()) {
                    // 찾은 것
                    cnt++;
                };
            };
            if(cnt == v.size()) found = true;
        };
        
        if(found) return;
        
        map<vector<string>, int> m;
        vector<string> row_check_v;
        for(int i = 0; i < copy_relation.size(); i++) {
            for(int idx: b) {
                row_check_v.push_back(copy_relation[i][idx]);
            };
            
            m.insert({row_check_v, 0});
            row_check_v.clear();
        };
        
        if(m.size() != copy_relation.size()) return;
        
        complete_key_v.push_back(b);
        
        return;
    };
    
    for(int i = start + 1; i < copy_relation[0].size(); i++) {
        b.push_back(i);
        combi(i, b, k);
        b.pop_back();
    };
    
    return;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    copy_relation = relation;
    int col_size = relation[0].size();
    
    for(int i = 1; i <= col_size; i++) {
        vector<int> b;
        combi(-1, b, i);
    };
    
    answer = complete_key_v.size();

    return answer;
}
