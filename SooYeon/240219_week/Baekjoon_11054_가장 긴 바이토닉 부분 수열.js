let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `10
// 1 5 2 1 4 3 4 5 2 1`.split('\n');

let n = Number(input[0]);
let arr = input.splice(1)[0].split(' ').map(Number);
let dp = Array.from(Array(2), () => Array(n).fill(0));

for(let i = 0; i < n; i++) {
  dp[0][i] = 1;
  for(let j = 0; j < i; j++) {
    if(arr[j] < arr[i]) {
      dp[0][i] = Math.max(dp[0][i], dp[0][j] + 1);
    }
  }
}

for(let i = n - 1; i >= 0; i--) {
  dp[1][i] = 1;
  for(let j = n - 1; j > i; j--) {
    if(arr[j] < arr[i]) {
      dp[1][i] = Math.max(dp[1][i], dp[1][j] + 1);
    }
  }
}

let answer = 0;
for(let i = 0; i < n; i++) {
  answer = Math.max(answer, dp[0][i] + dp[1][i]);
}

console.log(answer - 1);