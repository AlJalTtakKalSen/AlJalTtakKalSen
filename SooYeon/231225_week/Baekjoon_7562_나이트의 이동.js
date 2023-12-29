let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

let testCase = Number(input[0]);

let dy = [2, 1, -1, -2, -2, -1, 1, 2];
let dx = [1, 2, 2, 1, -1, -2, -2, -1];

class Queue {
  constructor() {
    this.arr = {};
    this.head = 0;
    this.tail = 0;
  }
  push(item) {
    this.arr[this.tail] = item;
    this.tail++;
  }
  pop() {
    delete this.arr[this.head];
    this.head++;
  }
  size() {
    return this.tail - this.head;
  }
  front() {
    return this.arr[this.head];
  }
}

let line = 1;
for(let t = 1; t <= testCase; t++) {
  let queue = new Queue();
  let n = Number(input[line]);
  let visited = Array.from(Array(Number(n + 1)), () => Array(Number(n + 1)).fill(0));
  
  let [x, y] = input[line + 1].split(' ').map(Number);
  let [destX, destY] = input[line + 2].split(' ').map(Number);

  queue.push([y, x]);
  visited[y][x] = 1;

  while(queue.size()) {
    let [cy, cx] = queue.front();
    queue.pop();

    if(cy == destY && cx == destX) {
      console.log(visited[cy][cx] - 1);
      break;
    }

    for(let i = 0; i < 8; i++) {
      let ny = cy + dy[i];
      let nx = cx + dx[i];

      if(ny >= n || ny < 0 || nx >= n || nx < 0) continue;
      if(visited[ny][nx]) continue;

      queue.push([ny, nx]);
      visited[ny][nx] = visited[cy][cx] + 1;
    }
  }

  line += 3;
}
