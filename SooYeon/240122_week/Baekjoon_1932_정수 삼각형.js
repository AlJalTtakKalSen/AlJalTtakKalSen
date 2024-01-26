let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `5
// 7
// 3 8
// 8 1 0
// 2 7 4 4
// 4 5 2 6 5`.split('\n'); // result: 30

let n = Number(input[0]);
let arr = [];
let d = Array.from(Array(n), () => Array(n).fill(0));

for(let i = 1; i <= n; i++) {
  arr.push(input[i].split(' ').map(Number));
}

d[0][0] = arr[0][0];
for(let i = 1; i < n; i++) {
  for(let j = 0; j <= i; j++) {
    if(j == 0) d[i][j] = arr[i][j] + d[i - 1][j];
    else if(j == i) d[i][j] = arr[i][j] + d[i - 1][j - 1];
    else d[i][j] = arr[i][j] + Math.max(d[i - 1][j - 1], d[i - 1][j]);
  }
}

console.log(Math.max(...d[n - 1]));