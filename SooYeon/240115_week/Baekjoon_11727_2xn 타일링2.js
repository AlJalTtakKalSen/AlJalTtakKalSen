let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `12`.split('\n');

let n = Number(input[0]);

let dp = new Array(1000);

dp[0] = 1;
dp[1] = 3;
dp[2] = 5;

for(let i = 3; i < dp.length; i++) {
  dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
}

console.log(dp[n - 1]);