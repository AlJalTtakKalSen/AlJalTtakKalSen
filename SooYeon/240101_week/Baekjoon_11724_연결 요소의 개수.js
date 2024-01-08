let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `6 8
// 1 2
// 2 5
// 5 1
// 3 4
// 4 6
// 5 4
// 2 4
// 2 3`.split('\n');

let [n, m] = input[0].split(' ').map(Number);
let arr = [];
for(let i = 0; i <= n; i++) arr.push([]);
let visited = new Array(n + 1).fill(false);

// 인접 리스트 저장
for(let i = 1; i <= m; i++) {
  let [a, b] = input[i].split(' ').map(Number);
  arr[a].push(b);
  arr[b].push(a);
}

function dfs(node) {
  // 현재 노드 방문 처리
  visited[node] = true;

  // 현재 노드와 연결된 다른 노드들 재귀적으로 방문
  for(i of arr[node]) {
    if(!visited[i]) dfs(i);
  }
}

let answer = 0;
for(let i = 1; i <= n; i++) {
  if(!visited[i]) {
    dfs(i);
    answer++;
  }
}

console.log(answer);
