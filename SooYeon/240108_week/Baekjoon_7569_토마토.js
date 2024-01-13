let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `2 2 3
// -1 -1
// -1 -1
// 1 -1
// 0 0
// -1 0
// -1 0`.split('\n');

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

let [m, n, h] = input[0].split(' ').map(Number);

let dy = [-1, 0, 1, 0, 0, 0];
let dx = [0, 1, 0, -1, 0, 0];
let dz = [0, 0, 0, 0, -1, 1];

// 3차원 배열로 생성
let arr = Array.from(Array(h), () => Array(n));
let visited = Array.from(Array(h), () => Array.from(Array(n), () => Array(m).fill(0)));
let tomato = [];

let line = 1;
let flag = false;
for(let i = 0; i < h; i++) {
  let tmp = [];
  let arrTmp;
  for(let j = 0; j < n; j++) {
    arrTmp = input[line].split(' ').map(Number);
    // 익은 토마토가 들어있는 위치 저장
    arrTmp.forEach((item, idx) => {
      if(item == 1) {
        visited[i][j][idx] = 1;
        tomato.push([i, j, idx]);
      }
      if(item == 0) flag = true;
    })
    tmp.push(arrTmp)
    line++;
  }
  arr[i] = tmp;
}

const queue = new Queue();
tomato.forEach((item) => queue.push(item));

// 1은 익은 토마토, 0은 익지 않은 토마토, -1은 토마토가 들어있지 않은 칸
let day = 0;
while(queue.size()) {
  let [z, y, x] = queue.front();
  queue.pop();

  for(let i = 0; i < 6; i++) {
    let ny = y + dy[i];
    let nx = x + dx[i];
    let nz = z + dz[i];

    if(ny >= n || ny < 0 || nx >= m || nx < 0 || nz >= h || nz < 0) continue;
    if(visited[nz][ny][nx] || arr[nz][ny][nx] !== 0) continue;

    queue.push([nz, ny, nx]);
    arr[nz][ny][nx] = 1;
    visited[nz][ny][nx] = visited[z][y][x] + 1;
    day = Math.max(day, visited[nz][ny][nx]);
  }
}

let answer = day - 1;
for(let i = 0; i < h; i++) {
  for(let j = 0; j < n; j++) {
    if(arr[i][j].includes(0)) answer = -1;
  }
}

if(!flag) answer = 0;
console.log(answer);
