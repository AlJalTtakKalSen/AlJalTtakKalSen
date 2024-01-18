let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `3
// 0 1 0
// 0 0 1
// 1 0 0`.split('\n');

const INF = 987654321;

// 플로이드 워셜 알고리즘
let n = Number(input[0]);
let floyd = Array.from(Array(n + 1), () => Array(n + 1).fill(INF));

for(let i = 1; i <= n; i++) {
  let line = input[i].split(' ').map(Number);

  for(let j = 0; j < line.length; j++) {
    if(line[j] == 1) floyd[i][j + 1] = 1;
  }
}

for(let k = 1; k <= n; k++) {
  for(let a = 1; a <= n; a++) {
    for(let b = 1; b <= n; b++) {
      floyd[a][b] = Math.min(floyd[a][b], floyd[a][k] + floyd[k][b]);
    }
  }
}

let answer = Array.from(Array(n), () => Array(n).fill(0));
for(let i = 1; i <= n; i++) {
  for(let j = 1; j <= n; j++) {
    if(floyd[i][j] != INF || floyd[i][j] === 0) answer[i-1][j-1] = 1;
  }
}

console.log(answer.map(v => v.join(' ')).join('\n'));