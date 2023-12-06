#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    int answer = s.length();
    
    for(int i = 1; i <= s.length() / 2; i++) {
        string pre_str = s.substr(0, i);
        string temp = "";
        int cnt = 1;
        
        for(int j = i; j < s.size(); j += i) {
            string current_str = s.substr(j, i);
            if(pre_str == current_str) {
                cnt++;
            } else {
                if(cnt > 1) temp += to_string(cnt);
                cnt = 1;
                temp += pre_str;
                pre_str = current_str;
            };
        };
        
        if(cnt > 1) temp += to_string(cnt);
        temp += pre_str;
        answer = temp.length() > answer ? answer : temp.length();
    };
    
    return answer;
}
