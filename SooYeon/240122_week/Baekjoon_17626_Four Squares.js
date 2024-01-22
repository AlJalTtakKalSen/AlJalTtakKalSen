let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `11339`.split('\n');

let n = Number(input[0]);

let dp = new Array(n + 1).fill(0);

dp[1] = 1;
dp[2] = 2;
dp[3] = 3;
dp[4] = 1;

let value = 4;
let square = 9;
for(let i = 5; i <= 50000; i++) {
  dp[i] = dp[i - 1] + 1;

  for(let j = 1; j * j <= i; j++) {
    dp[i] = Math.min(dp[i], dp[i - j * j] + 1);
  }
  
  if(i == square) {
    let sqrt = Math.sqrt(square) + 1;
    let tmp = square;
    square = sqrt * sqrt;
    value = tmp;
    dp[i] = 1;
  }
  // console.log(i, square, value, dp[i]);
  if(i == n) break;
}

console.log(dp[n]);