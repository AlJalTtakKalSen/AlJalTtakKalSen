let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `5 5 4
// 5 7 8 2 3
// 1 4 5
// 5 2 4
// 3 2 3
// 1 2 3`.split('\n');

let [n, m, r] = input[0].split(' ').map(Number);
let items = input[1].split(' ').map(Number);

let INF = 1e9;
let graph = Array.from(Array(n + 1), () => Array(n + 1).fill(INF));


for(let i = 2; i < r + 2; i++) {
  let [a, b, l] = input[i].split(' ').map(Number);
  graph[a][b] = Math.min(graph[a][b], l);
  graph[b][a] = Math.min(graph[b][a], l);
}

for(let i = 1; i <= n; i++) {
  graph[i][i] = 0;
}

for(let k = 1; k <= n; k++) {
  for(let a = 1; a <= n; a++) {
    for(let b = 1; b <= n; b++) {
      let cost = graph[a][k] + graph[k][b];
      graph[a][b] = Math.min(graph[a][b], cost);
    }
  }
}

let answer = 0;
for(let i = 1; i <= n; i++) {
  let sum = 0;
  for(let j = 1; j <= n; j++) {
    if(graph[i][j] <= m) {
      sum += items[j - 1];
    }
  }
  answer = Math.max(answer, sum);
}

console.log(answer);