let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `3
// 0 0 0
// 0 0 0
// 0 0 0`.split('\n');

let n = Number(input[0]);
let arr = input.slice(1).map(e => e.split(' ').map(Number));
let dp_max = Array.from(Array(n), () => Array(3).fill(0));
let dp_min = Array.from(Array(n), () => Array(3).fill(0));

arr[0].forEach((value, idx) => {
  dp_max[0][idx] = value;
  dp_min[0][idx] = value;
});

for(let i = 1; i < n; i++) {
  dp_max[i][0] = Math.max(dp_max[i - 1][0], dp_max[i - 1][1]) + arr[i][0];
  dp_max[i][1] = Math.max(dp_max[i - 1][0], dp_max[i - 1][1], dp_max[i - 1][2]) + arr[i][1];
  dp_max[i][2] = Math.max(dp_max[i - 1][1], dp_max[i - 1][2]) + arr[i][2];

  dp_min[i][0] = Math.min(dp_min[i - 1][0], dp_min[i - 1][1]) + arr[i][0];
  dp_min[i][1] = Math.min(dp_min[i - 1][0], dp_min[i - 1][1], dp_min[i - 1][2]) + arr[i][1];
  dp_min[i][2] = Math.min(dp_min[i - 1][1], dp_min[i - 1][2]) + arr[i][2];
}

let answer = [];
answer.push(Math.max(...dp_max[n - 1]));
answer.push(Math.min(...dp_min[n - 1]));

console.log(answer.join(' '));