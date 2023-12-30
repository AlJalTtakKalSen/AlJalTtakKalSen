let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

let n = Number(input[0]);
let m = Number(input[1]);

let INF = 987654321;
let arr = Array.from(Array(n + 1), () => Array(n + 1).fill(INF));

for(let i = 1; i <= n; i++) {
  arr[i][i] = 0; // 자기 자신으로의 경로는 0
}

for(let i = 2; i <= m; i++) {
  let [a, b, c] = input[i].split(' ').map(Number);
  arr[a][b] = Math.min(arr[a][b], c);
}

for(let k = 1; k <= n; k++) {
  for(let a = 1; a <= n; a++) {
    for(let b = 1; b <= n; b++) {
      arr[a][b] = Math.min(arr[a][b], arr[a][k] + arr[k][b]);
    }
  }
}

for(let a = 1; a <= n; a++) {
  let answer = '';
  for(let b = 1; b <= n; b++) {
    if(arr[a][b] == INF) answer += '0 ';
    else answer += arr[a][b] + ' ';
  }
  console.log(answer);
}
