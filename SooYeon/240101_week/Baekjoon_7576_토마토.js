let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

class Queue {
  constructor() {
    this.item = {};
    this.head = 0;
    this.tail = 0;
  }
  push(value) {
    this.item[this.tail] = value;
    this.tail++;
  }
  pop() {
    delete this.item[this.head];
    this.head++;
  }
  size() {
    return this.tail - this.head;
  }
  front() {
    return this.item[this.head];
  }
}

let dy = [-1, 0, 1, 0];
let dx = [0, 1, 0, -1];

let [m, n] = input[0].split(' ').map(Number);
let arr = new Array(n + 1);
let visited = Array.from(Array(n + 1), () => Array(m + 1).fill(0));

let tomato = [];
// 토마토에 대한 정보 입력받기
for(let i = 0; i < n; i++) {
  arr[i] = input[i + 1].split(' ').map(Number);

  // 익은 토마토의 위치 저장
  for(let j = 0; j < m; j++) {
    if(arr[i][j] == 1) tomato.push([i, j]);
  }
}

let queue = new Queue();
// 토마토가 익은 위치를 큐에 삽입
for(let i = 0; i < tomato.length; i++) {
  queue.push(tomato[i]);
}

// bfs 실행
let answer = 0;
while(queue.size()) {
  let [y, x, cnt] = queue.front();
  queue.pop();

  for(let i = 0; i < 4; i++) {
    let ny = y + dy[i];
    let nx = x + dx[i];

    if(ny >= n || ny < 0 || nx >= m || nx < 0) continue;
    if(arr[ny][nx] == 1 || arr[ny][nx] == -1) continue;
    if(visited[ny][nx]) continue;

    visited[ny][nx] = visited[y][x] + 1;
    queue.push([ny, nx]);
    answer = Math.max(answer, visited[ny][nx]);
  }
}

// 토마토가 모두 익었는지 확인
let isRipe = true;
for(let i = 0; i < n; i++) {
  for(let j = 0; j < m; j++) {
    if(visited[i][j] == 0 && arr[i][j] == 0) {
      isRipe = false;
      break;
    }
  }
  if(!isRipe) break;
}

if(isRipe) console.log(answer);
else console.log(-1);