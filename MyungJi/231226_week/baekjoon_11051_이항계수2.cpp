#include <bits/stdc++.h>
using namespace std;
int n, k;
int dp[1004][1004];
const int MOD = 10007;
int main(){
    //1. 입력받기
    cin >> n >> k;
    //2. dp 값 구하기
    for (int i=1;i<=n;i++){
        dp[i][0]=1;
        dp[i][i]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            dp[i][j] = (dp[i-1][j-1]+dp[i-1][j]) % MOD;
        }
    }
    //3. 정답 출력
    cout << dp[n][k] << "\n";
}