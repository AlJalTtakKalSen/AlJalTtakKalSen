#include <bits/stdc++.h>
using namespace std;

bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    // 문자열을 이어붙인 후 비교 연산을 통해 정렬
    // 순서를 달리해서 이어붙인 두 문자열을 비교해서 더 큰 값을 우선 정렬
    
    vector<string> v;
    for(int num: numbers) 
        v.push_back(to_string(num));
    
    sort(v.begin(), v.end(), compare);
    
    for(string s: v) answer += s;
    
    if(answer[0] == '0') return "0";
    
    return answer;
}
