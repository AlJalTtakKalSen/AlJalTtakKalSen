let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `6
// 10
// 20
// 15
// 25
// 10
// 20`.split('\n');

let n = Number(input[0]);

// 연속해서 세 계단을 밟을 수 없고, 마지막 계단은 반드시 밟아야 한다.
// 한 계단 또는 두 계단씩 오를 수 있다.

let arr = [];
for(let i = 1; i <= n; i++) {
  arr.push(Number(input[i]));
}

let dp = new Array(n).fill(0);
dp[0] = arr[0];
dp[1] = arr[0] + arr[1];
dp[2] = Math.max(arr[0] + arr[2], arr[1] + arr[2]);

// 점화식에 따라 dp 테이블 갱신
for(let i = 3; i < n; i++) {
  // i 번째 계단을 밟고 한 칸 뛰어서 밟는 경우, i번째 계단을 밟고 바로 앞의 계단을 밟는 경우
  dp[i] = Math.max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
}

console.log(dp[n - 1]);
