#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int zero_cnt = 0, cnt = 0;
    
    while(s != "1") {
        string binary_result = "";
        string tmp = "";
        cnt++;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') {
                zero_cnt++;
            } else {
                tmp += '1';
            }
        }
        
        int num = tmp.size();
        
        s = "";
        while(num >= 1) {
            s += to_string(num % 2);
            num /= 2;
        };
    }
    
    answer.push_back(cnt);
    answer.push_back(zero_cnt);
    
    return answer;
}