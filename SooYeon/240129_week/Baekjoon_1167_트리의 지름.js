// let fs = require('fs');
// let input = fs.readFileSync('/dev/stdin').toString().split('\n');

let input = `7
1 2 1 3 1 4 1 5 1 -1
2 1 1 6 5 7 5 -1
3 1 1 -1
4 1 1 -1
5 1 1 -1
6 2 5 -1
7 2 5 -1`.split('\n');

let v = Number(input[0]);
let graph = {};
let visited = new Array(v + 1).fill(false);

for(let i = 1; i <= v; i++) {
  let tmp = input[i].split(' ').map(Number);
  let node = tmp.shift();
  tmp.pop();
  graph[node] = [];
  while(tmp.length) {
    // 연결된 정점, 간선 가중치
    graph[node].push([tmp.shift(), tmp.shift()]);
  }
}

let max = 0, maxNode = 0;
const dfs = (node, w) => {
  visited[node] = true;
  if(max < w) {
    max = w;
    maxNode = node;
  }

  for(let [next, weight] of graph[node]) {
    if(!visited[next]) {
      dfs(next, w + weight);
    }
  }
}

dfs(1, 0);
visited.fill(false);
dfs(maxNode, 0);

console.log(max);