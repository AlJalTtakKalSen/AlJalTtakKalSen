let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `12
// 1 2 3
// 1 3 2
// 2 4 5
// 3 5 11
// 3 6 9
// 4 7 1
// 4 8 7
// 5 9 15
// 5 10 4
// 6 11 6
// 6 12 10`.split('\n');

let n = Number(input[0]);
let visited = Array(n + 1).fill(false);
let graph = Array.from({length: n + 1}, () => []);

for(let i = 1; i < n; i++) {
  let [parent, child, weight] = input[i].split(' ').map(Number);
  graph[parent].push([child, weight]);
  graph[child].push([parent, weight]);
}

class Queue {
  constructor() {
    this.items = {};
    this.head = 0;
    this.tail = 0;
  }
  push(item) {
    this.items[this.tail] = item;
    this.tail++;
  }
  pop() {
    delete this.items[this.head];
    this.head++;
  }
  size() {
    return this.tail - this.head;
  }
  front() {
    return this.items[this.head];
  }
}

const bfs = (start) => {
  visited = Array(n + 1).fill(false);

  let queue = new Queue();
  queue.push([start, 0]);
  visited[start] = true;

  let farNode = {node: 0, dist: 0};
  while(queue.size()) {
    let [node, dist] = queue.front();
    queue.pop();

    if(farNode.dist < dist) 
      farNode = {node: node, dist: dist};

    for(let [nextNode, weight] of graph[node]) {
      if(visited[nextNode]) continue;
      queue.push([nextNode, dist + weight]);
      visited[nextNode] = true;
    }
  }

  return farNode;
}

// 루트에서 가장 거리만 먼 노드를 찾는다.
// 루트에서 가장 거리만 먼 노드에서 가장 거리만 먼 노드를 찾는다.
console.log(bfs(bfs(1).node).dist);