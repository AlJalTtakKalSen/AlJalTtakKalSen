let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trimEnd().split('\n');

// let input = `7 8 2
// 0 0 0 0 0 0 0 9
// 0 0 0 0 3 0 0 8
// -1 0 5 0 0 0 22 0
// -1 8 0 0 0 0 0 0
// 0 0 0 0 0 10 43 0
// 0 0 5 0 15 0 0 0
// 0 0 40 0 0 0 20 0`.split('\n');

let [r, c, t] = input[0].split(' ').map(Number);
let room = input.slice(1).map(v => v.split(' ').map(Number));

let cleaner = [];
for(let i = 0; i < r; i++) {
  for(let j = 0; j < c; j++) {
    if(room[i][j] === -1) cleaner.push(i);
  }
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

let dy = [-1, 0, 1, 0];
let dx = [0, 1, 0, -1];

let queue = new Queue();
const spread = () => {
  for(let i = 0; i < r; i++) {
    for(let j = 0; j < c; j++) {
      if(room[i][j] > 0) queue.push([i, j]);
    }
  }

  let tmpRoom = Array.from(Array(r), () => Array(c).fill(0));
  tmpRoom[cleaner[0]][0] = -1;
  tmpRoom[cleaner[1]][0] = -1;
  while(queue.size()) {
    let [y, x] = queue.front();
    queue.pop();

    spreadAmount = Math.floor(room[y][x] / 5);
    
    let cnt = 0;
    for(let i = 0; i < 4; i++) {
      let ny = y + dy[i];
      let nx = x + dx[i];

      if(ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
      if(room[ny][nx] === -1) continue;

      cnt++;
      tmpRoom[ny][nx] += spreadAmount;
    }
    tmpRoom[y][x] += room[y][x] - spreadAmount * cnt;
  }

  for(let i = 0; i < r; i++) {
    for(let j = 0; j < c; j++) {
      room[i][j] = tmpRoom[i][j];
    }
  }
}

const clean = () => {
  let y = cleaner[0];
  for(let i = y - 1; i > 0; i--) room[i][0] = room[i - 1][0];
  for(let i = 0; i < c - 1; i++) room[0][i] = room[0][i + 1];
  for(let i = 0; i < y; i++) room[i][c - 1] = room[i + 1][c - 1];
  for(let i = c - 1; i > 0; i--) room[y][i] = room[y][i - 1];
  room[y][1] = 0;
  

  // 공기청정기 아래쪽, 시계방향
  y = cleaner[1];
  for(let i = y + 1; i < r - 1; i++) room[i][0] = room[i + 1][0];
  for(let i = 0; i < c - 1; i++) room[r - 1][i] = room[r - 1][i + 1];
  for(let i = r - 1; i > y; i--) room[i][c - 1] = room[i - 1][c - 1];
  for(let i = c - 1; i > 0; i--) room[y][i] = room[y][i - 1];
  room[y][1] = 0;
}

// t초 동안 반복
for(let i = 0; i < t; i++) {
  spread();
  clean();
}

let answer = 0;
for(let i = 0; i < r; i++) {
  for(let j = 0; j < c; j++) {
    answer += room[i][j];
  }
}

console.log(answer + 2);