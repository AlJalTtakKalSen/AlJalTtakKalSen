#include <bits/stdc++.h>
using namespace std;

long long cal(char oper, long long a, long long b) {
    if(oper == '+') return a + b;
    else if(oper == '*') return a * b;
    else return a - b;
}

long long solution(string expression) {
    long long answer = 0;
    
    vector<char> opers_v;
    vector<long long> nums_v;
    vector<char> const_oper = {'+', '-', '*'};
    
    string num = "";
    // 두 벡터에 연산자, 숫자 나눠서 저장
    for(int i = 0; i < expression.size(); i++) {
        if(expression[i] >= '0' && expression[i] <= '9') {
            num += expression[i];
        } else {
            if(num.size()) nums_v.push_back(stoi(num));
            opers_v.push_back(expression[i]);
            num = "";
        };
    };
    
    nums_v.push_back(stoi(num));
    // next_permutation 쓸 때는 정렬 필수
    sort(const_oper.begin(), const_oper.end());
    
    // 순열로 완전 탐색
    do {
        vector<long long> temp_nums = nums_v;
        vector<char> temp_operator = opers_v;
        
        for(int i = 0; i < const_oper.size(); i++) {
            for(int j = 0; j < temp_operator.size(); j++) {
                // 현재 순열의 연산자가 계산 연산자라면
                if(temp_operator[j] == const_oper[i]) {
                    temp_nums[j] = cal(const_oper[i], temp_nums[j], temp_nums[j + 1]);
                    
                    temp_nums.erase(temp_nums.begin() + j + 1);
                    temp_operator.erase(temp_operator.begin() + j);
                    // 벡터 값들 중 하나가 빠졌으므로
                    j--;
                }
            }
        }
        
        answer = max(answer, abs(temp_nums[0]));
    } while(next_permutation(const_oper.begin(), const_oper.end()));
    
    return answer;
}
