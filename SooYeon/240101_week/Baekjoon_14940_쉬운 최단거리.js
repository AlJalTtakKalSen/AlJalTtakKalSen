let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `15 15
// 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1 0 0 0 0 1
// 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1 0 1 0 0 0
// 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1`.split('\n');

let [n, m] = input[0].split(' ').map(Number);
let arr = new Array(n + 1).fill([]);
let visited = Array.from(Array(n), () => Array(m).fill(0));
let arrive = [];
let start = [n - 1, m - 1];
let zero = [];

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
  front() {
    return this.items[this.head];
  }
  size() {
    return this.tail - this.head;
  }
}

// 땅 정보 입력, 도착지점 인덱스 저장
for(let i = 0; i < n; i++) arr[i] = [];
for(let i = 1; i <= n; i++) {
  arr[i - 1] = input[i].split(' ').map(Number);
  for(let j = 0; j < m; j++) {
    if(arr[i-1][j] == 2) arrive = [i-1, j];
    else if(arr[i-1][j] == 0) zero.push([i-1, j]);
  }
}

let queue = new Queue();
queue.push([arrive[0], arrive[1]]);

while(queue.size()) {
  let [y, x] = queue.front();
  queue.pop();

  for(let i = 0; i < 4; i++) {
    let ny = y + dy[i];
    let nx = x + dx[i];

    if(ny >= n || ny < 0 || nx >= m || nx < 0) continue;
    if(arr[ny][nx] == 0 || visited[ny][nx]) continue;

    queue.push([ny, nx]);
    visited[ny][nx] = visited[y][x] + 1;
  }
}

for(let i = 0; i < n; i++) {
  for(let j = 0; j < m; j++) {
    if(visited[i][j] == 0) visited[i][j] = -1;
  }
}

for(let [y, x] of zero) visited[y][x] = 0;
visited[arrive[0]][arrive[1]] = 0;

console.log(visited.map((v) => v.join(' ')).join('\n'));
