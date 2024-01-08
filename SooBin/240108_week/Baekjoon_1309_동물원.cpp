#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

int main() 
{
    int dp[100001];
    int N;
    cin >> N;
    dp[1] = 3;
    dp[2] = 7;
    for (int i = 3; i <= N; i++) 
    {
        dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901;
    }
    cout << dp[N];
    return 0;
}