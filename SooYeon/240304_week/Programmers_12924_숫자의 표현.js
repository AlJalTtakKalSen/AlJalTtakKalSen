// 연속된 자연수들로 n을 표현하는 방법의 수

function solution(n) {
  let dp = new Array(n).fill(0);

  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 3;

  for (let i = 3; i <= n; i++) {
    dp[i] = dp[i - 1] + i;
  }

  let cnt = 0;
  for (let i = Math.ceil(n / 2); i >= 1; i--) {
    if (dp[i] === n) {
      cnt++;
      continue;
    }

    for (let j = i - 1; j >= 1; j--) {
      if (dp[i] - dp[j] > n) break;
      if (n === dp[i] - dp[j]) {
        cnt++;
        break;
      }
    }
  }

  // 자기 자신에 대한 cnt 추가
  if (n !== 1) cnt++;

  return cnt;
}
