#include <bits/stdc++.h>

using namespace std;
string a, b;
int dp[1004][1004];
int main(void) {
    // 1. 입력받기
    cin >> a >> b;
    // 2. dp 수행
    // a.size()까지인 이유는 1일때 첫번째 문자를 비교하므로, n일때 n-1까지의 전체 문자를 비교할 수 있기 때문
    for(int i=1;i<=a.size();i++){ 
        for(int j=1;j<=b.size();j++){
            if(a[i-1]==b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    // 3. 정답 출력
    cout << dp[a.size()][b.size()];

    return 0;
}