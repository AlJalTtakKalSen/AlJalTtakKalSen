let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `3 3
// IOX
// OXP
// XPP`.split('\n');

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

let [n, m] = input[0].split(' ').map(Number);
let arr = [];
let visited = Array.from(Array(n), () => Array(m).fill(false));

let doyeon;
for(let i = 1; i <= n; i++) {
  arr.push(input[i].split(''));
  arr[i-1].forEach((item, idx) => {
    if(item == 'I') doyeon = [i - 1, idx];
  });
}

let dy = [-1, 0, 1, 0];
let dx = [0, 1, 0, -1];

let answer = 0;
let queue = new Queue();
queue.push([doyeon[0], doyeon[1]]);

while(queue.size()) {
  let [y, x] = queue.front();
  queue.pop();

  for(let i = 0; i < 4; i++) {
    let ny = y + dy[i];
    let nx = x + dx[i];

    if(ny >= n || ny < 0 || nx >= m || nx < 0) continue;
    if(visited[ny][nx] || arr[ny][nx] == 'X') continue;

    if(arr[ny][nx] == 'P') answer++;

    visited[ny][nx] = true;
    queue.push([ny, nx]);
  }
}

if(answer) console.log(answer);
else console.log('TT');