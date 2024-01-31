let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `7
// 1 6
// 6 3
// 3 5
// 4 1
// 2 4
// 4 7`.split('\n');

let n = Number(input[0]);

let adj = {};
for(let i = 1; i < n; i++) {
  let [a, b] = input[i].split(' ').map(Number);
  if(!adj[a]) {
    adj[a] = [];
  }
  if(!adj[b]) {
    adj[b] = [];
  }
  
  adj[a].push(b);
  adj[b].push(a);
}

let parent = Array(n + 1).fill(0);
let visited = Array(n + 1).fill(false);
let queue = [1];
visited[1] = true;

while(queue.length) {
  let now = queue.shift(); 
  
  for(let i = 0; i < adj[now].length; i++) {
    let next = adj[now][i];
    
    if(!visited[next]) {
      parent[next] = now;
      visited[next] = true;
      queue.push(next);
    }
  }
}

let answer = [];
for(let i = 2; i <= n; i++) {
  answer.push(parent[i]);
}

console.log(answer.join('\n'));