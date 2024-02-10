let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `4 4
// 0111
// 1111
// 1111
// 1110`.split('\n');

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
let map = [];
let visited = Array.from({length: n}, () => Array.from({length: m}, () => Array.from({length: 2}, () => 0)));

for(let i = 1; i <= n; i++) {
  map.push(input[i].split('').map(Number));
}

let dy = [-1, 0, 1, 0];
let dx = [0, 1, 0, -1];

const bfs = (fy, fx, fw) => {
  let queue = new Queue();
  queue.push([fy, fx, fw]);
  visited[fy][fx][fw] = 1;

  while(queue.size()) {
    let [y, x, broken] = queue.front();
    queue.pop();

    if(y === n - 1 && x === m - 1) {
      return visited[y][x][broken];
    }

    for(let i = 0; i < 4; i++) {
      let ny = y + dy[i];
      let nx = x + dx[i];

      if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if(visited[ny][nx][broken]) continue; // 이미 방문한 곳 continue;

      // 벽을 만나고 처음으로 부순 후엔 그 다음 벽을 또 만나도 부술 수 없다.
      if(map[ny][nx] === 1 && !broken) { // 벽이면서 벽을 부순 적이 없는 경우
        queue.push([ny, nx, 1]); // 벽을 부순다.
        // 벽을 부순 후엔 이동거리가 visited[y][x][벽을 부순 후 이동]으로 계산된다.
        visited[ny][nx][1] = visited[y][x][broken] + 1;
      }
      if(map[ny][nx] === 0) { // 벽이 아닌 경우
        queue.push([ny, nx, broken]);
        visited[ny][nx][broken] = visited[y][x][broken] + 1;
      }
    }
  }
  return -1;
}

console.log(bfs(0, 0, 0));