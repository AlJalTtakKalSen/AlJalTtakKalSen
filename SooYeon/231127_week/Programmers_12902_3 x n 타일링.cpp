#include <bits/stdc++.h>
using namespace std;
long long dp[5001];

long long process(int n) {
  // n이 0이면 곱할 때 0이 되면 안되므로 1을 리턴
  // n이 1이면 타일을 채울 수 없으므로 0을 리턴
  // n이 2이면 총 3가지의 경우가 나오므로 3을 리턴
    if(n == 0) return 1;
    if(n == 1) return 0;
    if(n == 2) return 3;
    if(dp[n]) return dp[n];
    else {
      // f(n) = 3 * f(n - 2) + 2 * f(n - 4) + 2 * f(n - 6) + ... + 2 * f(0)
        dp[n] = 3 * process(n - 2);
        for(int i = 4; i <= n; i+=2) {
            dp[n] += 2 * process(n - i);
        };
        dp[n] %= 1000000007;
        return dp[n];
    };
};

// 세로가 3이기 때문에 가로가 홀수인 경우는 타일을 채울 수 없음
int solution(int n) {
    int answer = 0;
    
    answer = process(n);
    
    return answer;
}