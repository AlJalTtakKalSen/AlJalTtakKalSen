let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `ACAA
// AAACBA`.split('\n');

let str1 = input[0];
let str2 = input[1];

let dp = Array.from(Array(str1.length + 1), () => Array(str2.length + 1).fill(0));

for(let i = 1; i <= str1.length; i++) {
  for(let j = 1; j <= str2.length; j++) {
    if(str1[i - 1] === str2[j - 1]) {
      dp[i][j] = dp[i - 1][j - 1] + 1;
    }
    else {
      let top = dp[i - 1][j];
      let left = dp[i][j - 1];
      dp[i][j] = Math.max(top, left);
    }
  }
}

console.log(dp[str1.length][str2.length]);