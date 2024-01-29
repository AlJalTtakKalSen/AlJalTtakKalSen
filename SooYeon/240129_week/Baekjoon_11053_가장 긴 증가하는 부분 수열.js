let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `6
// 10 20 10 30 20 50`.split('\n');

let n = Number(input[0]);
let arr = input[1].split(' ').map(Number);
let dp = new Array(n).fill(1);

for(let i = 1; i < n; i++) {
  for(let j = 0; j < i; j++) {
    if(arr[i] > arr[j]) {
      dp[i] = Math.max(dp[i], dp[j] + 1)
    }
  }
}

console.log(Math.max(...dp));