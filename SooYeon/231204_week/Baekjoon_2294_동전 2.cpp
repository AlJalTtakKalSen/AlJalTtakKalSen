#include <bits/stdc++.h>
using namespace std;
int n, k;
int coin[101], dp[10010];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    cin >> coin[i]; // 1 5 12
  };

  // 동전의 최소값을 찾아야 하므로 dp 배열을 최대값으로 초기화
  for(int i = 1; i <= k; i++) {
    dp[i] = 987654321;
  }

  // 현재 값이랑 이전 값 중 더 작은 값을 찾아서 dp 배열에 저장
  // 이전 값 예제: k 값이 7인 경우 k == 5일 때의 dp 배열에 저장된 값 + k == 2일 때 dp 배열에 저장된 값
  // k == 5 일 때는 최소 값이 1일테니 1 + 2일 것임

  // k가 0일 땐 0으로 초기화
  dp[0] = 0;

  for(int i = 1; i <= n; i++) {
    // 테스트로 받은 동전 값부터 시작
    for(int j = coin[i]; j <= k; j++) {
      // 현재 값이랑 이전 값 중 더 작은 값을 찾아서 dp 배열에 저장
      dp[j] = min(dp[j], dp[j - coin[i]] + 1);
    };
  };

  if(dp[k] == 987654321) cout << -1 << "\n";
  else cout << dp[k] << "\n";

  return 0;
}