#include <bits/stdc++.h>
using namespace std;

stack<char> op; // 연산자 저장 스택

//우선순위 정하는 함수
int prio(char c){
    if (c=='*' || c=='/') return 2; // 가장 높음
    else if (c=='+' || c=='-') return 1;
    else return -1;
}

int main(){
    //1. 입력받기
    string str="";
    cin  >> str;
    string result="";
    //2. 구현
    for(int i=0;i<str.length();i++){
        char c = str[i];
        if (('A'<=c) && (c<='Z')) result += c;
        else if (c=='(') op.push(c);
        else if (c==')'){
            while (op.top() != '('){
                result += op.top();
                op.pop();
            }
            op.pop(); // '(' 제거
        }
        else{ // 이전 연산자가 더 크거나 같은 우선순위일 경우 출력
            while (!op.empty() && prio(op.top())>=prio(c)){
                result += op.top();
                op.pop();
            } op.push(c);
        } 
    }
    // 스택에 있는 값 모두 출력
    while(!op.empty()){
        result += op.top();
        op.pop();
    }
    // 3. 정답 출력
    cout << result;
}