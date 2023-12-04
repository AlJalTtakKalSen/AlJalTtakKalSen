#include <bits/stdc++.h>
using namespace std;
vector<string> copy_skill_trees;
int result = 0;
bool flag = false;

void dfs(string skill, string skill_tree, int end_idx, int current_idx, vector<char> get_skill_idx_v) {
    auto it = skill.find(skill_tree[current_idx]);
    if(it != string::npos) {
        // 스킬에 포함된다면 얻은 스킬 다음인지 확인
        if(get_skill_idx_v[get_skill_idx_v.size() - 1] != skill[it]) {
            // 얻은 스킬 다음 스킬이 아니라면 리턴
            return;
        }
        else {
            // 얻은 스킬 다음이라면 스킬 벡터에 저장
            get_skill_idx_v.push_back(skill[it+1]);
            
            // 다음 스킬로 옮기기 전, 스킬 트리의 마지막 문자인지 확인
            if(skill_tree.size() == current_idx + 1) {
                flag = true;
                return;
            }
            
            dfs(skill, skill_tree, end_idx, current_idx + 1, get_skill_idx_v);
        };
    }
    else {
        // 스킬에 포함되지 않는 스킬이라면, 다음으로 넘김
        if(skill_tree.size() == current_idx + 1) {
            flag = true;
            return;
        }
        
        dfs(skill, skill_tree, end_idx, current_idx + 1, get_skill_idx_v);
    };
    
}

int solution(string skill, vector<string> skill_trees) {
    int answer = -1;
    vector<string> copy_skill_trees;
    vector<char> skill_idx_v;
    skill_idx_v.push_back(skill[0]);
    
    for(int i = 0; i < skill_trees.size(); i++) {
        flag = false;
        dfs(skill, skill_trees[i], skill_trees[i].size() - 1, 0, skill_idx_v);
        if(flag) result++;
    };
    
    answer = result;
    
    return answer;
}