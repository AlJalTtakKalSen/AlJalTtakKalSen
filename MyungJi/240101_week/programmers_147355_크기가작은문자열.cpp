#include <bits/stdc++.h>

using namespace std;
string str;
int solution(string t, string p) {
    int answer = 0;
    //1. 부분 문자열 구하기
    int pSize = p.size();
    for (int i=0;i<=t.size()-pSize;i++){
        str = t.substr(i, pSize);
        while (str[0]=='0'){
            str.erase(0, 1);
        } 
        //2. 숫자 비교하기
        if (str.size() < p.size()) answer++;
        else if ((str.size() == p.size()) && str <= p) answer++;
    }
    //3. 정답 출력하기
    return answer;
}