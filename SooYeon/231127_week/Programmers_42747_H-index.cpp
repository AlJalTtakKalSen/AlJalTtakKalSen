#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int solution(vector<int> citations) {
    // 인용된 논문 개수
    int answer = 0;
    
    // 내림차순으로 인용 횟수 정렬
    sort(citations.begin(), citations.end(), compare);
    
    // 논문 인용 횟수가 인용된 논문 개수와 같거나 적어지면 break
    // 인용된 논문 개수가 논문 인용 횟수보다 커지는 순간, 문제에서 원하는 h편 이상을 적용할 수 없음
    for(int i = 0; i < citations.size(); i++) {
        if(answer >= citations[i]) break;
        answer++;
    };
    
    return answer;
}
