#include <bits/stdc++.h>
using namespace std;

// 자연수를 3진법으로 만드는 방법 -> 3으로 나눈 나머지를 vector 저장 (뒤에서부터 채워짐)
// 3으로 나눈 값으로 반복
int solution(int n) {
    int answer = 0;
    string s_nums = "";
    vector<int> v;
    
    // 반전된 3진법으로 만들기
    while(n) {
        v.push_back(n % 3);
        n /= 3;
    }

    int mul = 1;
    for(int i = v.size() - 1; i >= 0; i--) {
        answer += v[i] * mul;
        mul *= 3;
    }
    
    return answer;
}
