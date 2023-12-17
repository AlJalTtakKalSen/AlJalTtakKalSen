#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
int dp[2000004];
int solution(int x, int y, int n) {
    int answer = 0;
    fill (dp, dp+2000004, INF);
    dp[x]=0;
    for (int i=x;i<=y;i++){
        if (i + n < 2000004) dp[i + n] = min(dp[i + n], dp[i] + 1);
        if (i * 2 < 2000004) dp[i*2] = min(dp[i]+1, dp[i*2]);
        if (i * 3 < 2000004) dp[i*3] = min(dp[i]+1, dp[i*3]);
    }
    if (dp[y]==INF) return -1;
    else return dp[y];
}