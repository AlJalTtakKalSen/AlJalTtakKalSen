#include <bits/stdc++.h>
using namespace std;
int tri[504][504];
int n;
long long answer;
long long dp[504][504];

int main(){
    //1. 입력받기
    cin >> n;
    for (int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cin >> tri[i][j];
        }
    }
    //2. 합 구하기
    dp[0][0]= tri[0][0];
    for (int i=0;i<n-1;i++){
        for (int j=0;j<i+1;j++){ 
            dp[i+1][j] = dp[i][j] + tri[i+1][j];
            dp[i+1][j+1] = dp[i][j] + tri[i+1][j+1];
        }
    }
    //3. 답 구하기
    for (int i=0;i<n;i++){
        if (answer<dp[n-1][i]) answer = dp[n-1][i];
    }
    //4. 정답 출력
    cout << answer;
}