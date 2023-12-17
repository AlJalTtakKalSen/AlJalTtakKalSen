#include <bits/stdc++.h>
using namespace std;
int k = 2, total_num;
vector<int> sum_list;
vector<int> copy_list;

void combi(int start, vector<int> b) {
    if(b.size() == 2) {
        int sum = copy_list[b[0]] + copy_list[b[1]];
        if(find(sum_list.begin(), sum_list.end(), sum) == sum_list.end()) {
            sum_list.push_back(sum);
        }
        return;
    };
    
    for(int i = start + 1; i < total_num; i++) {
        b.push_back(i);
        combi(i, b);
        b.pop_back();
    };
    
    return;
}

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    total_num = numbers.size();
    copy_list = numbers;
    
    vector<int> b;
    combi(-1, b);
    
    for(int i = 0; i < sum_list.size(); i++) {
        answer.push_back(sum_list[i]);
    };
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
