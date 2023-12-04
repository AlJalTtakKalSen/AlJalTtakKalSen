#include <bits/stdc++.h>
using namespace std;
int n, k;
int coins[10004];
int dp[10004];
int main() {
    //1. 입력 받기
    cin >> n >> k;
    for (int i=0;i<n;i++){
        cin >> coins[i];
    } 
    //2. 동전의 경우의 수 구하기
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=coins[i];j<=k;j++){
            dp[j] += dp[j-coins[i]];
        }
    }
    //3. 정답 출력
    cout << dp[k];

    return 0;
}
