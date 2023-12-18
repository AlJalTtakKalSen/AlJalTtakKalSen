#include <bits/stdc++.h>
#define INF 1e9
#define MX 2000004
using namespace std;
int dp[MX];
int solution(int x, int y, int n) {
    fill (dp, dp+MX, INF);
    dp[x]=0;
    for (int i=x;i<=y;i++){
        if (i + n < MX) dp[i + n] = min(dp[i + n], dp[i] + 1);
        if (i * 2 < MX) dp[i*2] = min(dp[i]+1, dp[i*2]);
        if (i * 3 < MX) dp[i*3] = min(dp[i]+1, dp[i*3]);
    }
    if (dp[y]==INF) return -1;
    else return dp[y];
}