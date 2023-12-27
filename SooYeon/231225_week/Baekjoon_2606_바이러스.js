let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

let n = Number(input[0]);
let m = Number(input[1]);
let arr = [];
for(let i = 1; i <= n; i++) arr[i] = [];
let visited = new Array(n + 1).fill(false);

for(let i = 2; i < m + 2; i++) {
  let [a, b] = input[i].split(' ').map(Number);
  arr[a].push(b);
  arr[b].push(a);
}

let answer = 0;
function dfs(v) {
  visited[v] = true;
  for(let x of arr[v]) {
    if(!visited[x]) {
      answer++;
      dfs(x);
    }
  }
}

dfs(1);
console.log(answer);