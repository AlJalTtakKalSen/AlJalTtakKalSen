let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `9`.split('\n');

let n = Number(input[0]);
let arr = new Array(n + 1).fill(0);

arr[0] = 1;
arr[1] = 1;
arr[2] = 2;
arr[3] = 3;

for(let i = 4; i <= n; i++) {
  arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
}

console.log(arr[n]);
