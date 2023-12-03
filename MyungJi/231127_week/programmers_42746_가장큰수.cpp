#include <bits/stdc++.h>

using namespace std;
vector<string> str;

bool cmp(string a, string b){
    return a+b > b+a;
}
string solution(vector<int> numbers) {
    string answer = "";
    //1. 문자열로 바꾸기
    for(int n:numbers) str.push_back(to_string(n));
    //2. 정렬
    sort(str.begin(), str.end(), cmp);
    //3. 정답 출력
    if(str[0]=="0") return "0";
    for(string s:str) answer+=s;
    
    return answer;
}