let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `8
// 71 39 44
// 32 83 55
// 51 37 63
// 89 29 100
// 83 58 11
// 65 13 15
// 47 25 29
// 60 66 19`.split('\n');

// 집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다.
// 인접한 집은 같은 색으로 칠할 수 없다.

let n = Number(input[0]);
let arr = [];
let d = Array.from(Array(n), () => Array(3).fill(987654321));

for(let i = 1; i <= n; i++) arr.push(input[i].split(' ').map(Number));

// 첫 번재 집은 그대로 최소값으로 기록
d[0][0] = arr[0][0];
d[0][1] = arr[0][1];
d[0][2] = arr[0][2];

for(let i = 1; i < n; i++) {
  for(let j = 0; j < 3; j++) {
    for(let k = 0; k < 3; k++) {
      if(j !== k) d[i][j] = Math.min(d[i][j], arr[i][j] + d[i - 1][k])
    }
  }
}

console.log(Math.min(d[n - 1][0], d[n-1][1], d[n-1][2]));