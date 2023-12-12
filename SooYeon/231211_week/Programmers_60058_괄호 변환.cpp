#include <bits/stdc++.h>
using namespace std;

// 1. 균현잡힌 문자열 뽑기
// 2. 뽑은 문자열이 올바른지 확인
// 3. 올바르지 않다면 균형잡힌 문자열 뽑기 반복(1,2)
// 4. v에 대해서도 1, 2번 계속 반복
// 5. v가 "" 이라면 "" 리턴

// 뽑은 문자열이 올바른지 확인하는 함수
bool isRight(string s) {
    stack<char> st;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') st.push('(');
        else {
            if(!st.empty() && st.top() == '(') st.pop();
            else return false;
        }
    }
    return true;
}

// 균형잡힌 문자열인지 확인하는 함수
string isBalance(string s) {
    int left = 0, right = 0;
    
    // v가 빈 문자열이라면 리턴
    if(s == "") return "";
    
    string u = "";
    string v = "";
    
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') right++;
        else left++;
        
        if(left == right) {
            // u가 올바른지 확인
            u = s.substr(0, i+1);
            v = s.substr(i+1);
            break;
        }
    }
    
    bool check = isRight(u);
    if(check) {
        u += isBalance(v);
        return u;
    } else {
        // u가 올바르지 않다면 
        string reverse = "";
        reverse += "(";
        reverse += isBalance(v);
        reverse += ")";
        
        u.erase(u.begin());
        u.erase(u.end() - 1);
        
        for(int j = 0; j < u.size(); j++) {
            if(u[j] == '(') reverse += ')';
            else reverse += '(';
        };
                
        return reverse;
    }
}

string solution(string p) {
    string answer = isBalance(p);
    
    return answer;
}