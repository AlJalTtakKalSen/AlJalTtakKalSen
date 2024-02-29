let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `8 9
// 0 0 0 0 0 0 0 0 0
// 0 0 0 1 1 0 0 0 0
// 0 0 0 1 1 0 1 1 0
// 0 0 1 1 1 1 1 1 0
// 0 0 1 1 1 1 1 0 0
// 0 0 1 1 0 1 1 0 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0`.split('\n');

let [n, m] = input[0].split(' ').map(Number);
let graph = input.slice(1).map(li => li.split(' ').map(Number));

let dy = [-1, 0, 1, 0];
let dx = [0, 1, 0, -1];

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

const bfs = () => {
  let visited = Array.from(Array(n), () => Array(m).fill(false));
  let queue = new Queue();

  queue.push([0, 0]);
  visited[0][0] = true;

  while(queue.size()) {
    let [y, x] = queue.front();
    queue.pop();

    for(let i = 0; i < 4; i++) {
      let ny = y + dy[i];
      let nx = x + dx[i];

      if(ny >= n || ny < 0 || nx >= m || nx < 0) continue;
      if(visited[ny][nx]) continue;

      if(graph[ny][nx] >= 1) {
        graph[ny][nx]++;
      } else {
        queue.push([ny, nx]);
        visited[ny][nx] = true;
      }
    }
  }
}

const melt = () => {
  let finish = true;
  for(let i = 0; i < n; i++) {
    for(let j = 0; j < m; j++) {
      if(graph[i][j] > 2) {
        finish = false;
        graph[i][j] = 0;
      }
      if(graph[i][j] === 2) graph[i][j] = 1;
    }
  }

  return finish;
}

let time = 0;
while(true) {
  bfs();
  if(melt()) break;
  time++;
}

console.log(time);