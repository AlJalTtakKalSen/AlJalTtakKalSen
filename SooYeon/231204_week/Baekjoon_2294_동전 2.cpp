#include <bits/stdc++.h>
using namespace std;
int dp[100002];

int main() {
  int n, k;
  cin >> n >> k;

  for(int i = 1; i <= k; i++) dp[i] = 987654321;

  int coin[102];
  for(int i = 1; i <= n; i++) {
    cin >> coin[i];
    dp[coin[i]] = 1;
  };

  dp[0] = 0;

  for(int i = 1; i <= n; i++) {
    for(int j = coin[i]; j <= k; j++) {
      dp[j] = min(dp[j], dp[j - coin[i]] + 1);
    };
  };

  if(dp[k] == 987654321) cout << -1 << "\n";
  else cout << dp[k] << "\n";

  return 0;
}