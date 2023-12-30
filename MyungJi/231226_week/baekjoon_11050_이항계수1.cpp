#include <bits/stdc++.h>
using namespace std;
int n, k, p1, p2;
long long answer = 1;

int main(){
    cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
    // 1. 입력받기
    cin >> n >> k;
    p1 = k;
    p2 = n-k;
    // 2. 곱하면서 나누기
    for(int i=n;i>=1;i--){
        answer *= i;
        while ((p1>1) && (answer%p1==0)) answer /= p1--;
        while ((p2>1) && (answer%p2==0)) answer /= p2--;
    }
    while ((p1>1) && (answer%p1==0)) answer /= p1--;
    while ((p2>1) && (answer%p2==0)) answer /= p2--;
    // 3. 정답 출력
    cout << answer;    
}