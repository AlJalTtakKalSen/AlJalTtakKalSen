let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `10
// 5 3 2 0 0 1 2 0 4 0
// 3 0 3 1 0 0 3 0 6 1
// 0 3 0 5 0 5 4 4 2 5
// 3 0 0 3 0 6 1 5 4 2
// 1 0 2 0 2 0 3 0 0 6
// 1 1 1 1 1 1 1 1 0 0
// 2 0 2 1 9 6 0 0 4 3
// 1 6 1 0 6 0 5 0 1 0
// 6 5 4 0 1 2 1 3 5 0
// 0 1 6 6 1 4 3 0 1 1`.split('\n');

let n = Number(input[0]);
let map = input.slice(1).map(el => el.split(' ').map(Number));
let shark = {size: 2, x: 0, y: 0, time: 0, eat: 0};
let fish = [];

for(let i = 0; i < n; i++) {
  for(let j = 0; j < n; j++) {
    if(map[i][j] === 9) {
      shark.y = i;
      shark.x = j;
    }
    if(map[i][j] !== 0 && map[i][j] !== 9) {
      fish.push({y: i, x: j, size: map[i][j]});
    }
  }
}

map[shark.y][shark.x] = 0;

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

let visited = Array.from(Array(n), () => Array(n).fill(0));
const bfs = () => {
  let queue = new Queue();
  visited = Array.from(Array(n), () => Array(n).fill(0));
  queue.push([shark.y, shark.x]);

  while(queue.size()) {
    let [y, x] = queue.front();
    queue.pop();

    for(let i = 0; i < 4; i++) {
      let ny = y + dy[i];
      let nx = x + dx[i];

      if(ny >= n || ny < 0 || nx >= n || nx < 0) continue;
      if(visited[ny][nx] !== 0 || map[ny][nx] > shark.size) continue;

      visited[ny][nx] = visited[y][x] + 1;
      queue.push([ny, nx]);
    }
  }
  return 0;
}

// 물고기 크기가 작은 순으로 정렬
// 물고기의 크기가 작은 위치 중 가장 가까운 위치의 물고기를 먹는다.

const findShortDistFish = (smallFish) => {
  let min = 1e9;
  let shortDistFish = [];
  for(let i = 0; i < smallFish.length; i++) {
    // console.log(visited);
    let dist = visited[smallFish[i].y][smallFish[i].x];
    if(dist === 0) continue;
    smallFish[i].dist = dist;
    min = Math.min(min, dist);
  }

  for(let i = 0; i < smallFish.length; i++) {
    if(smallFish[i].dist === min) {
      shortDistFish.push(smallFish[i]);
    }
  }

  shortDistFish.sort((a, b) => {
    if(a.y === b.y) {
      return a.x - b.x;
    } else {
      return a.y - b.y;
    }
  })

  return shortDistFish;
}

const findSmallFish = () => {
  let smallFish = [];
  for(let i = 0; i < fish.length; i++) {
    if(fish[i].size < shark.size) {
      smallFish.push(fish[i]);
    }
  }
  return smallFish;

}

const eatFish = () => {
  let smallFish = findSmallFish();
  bfs();
  let shortDistFish = findShortDistFish(smallFish);
  
  // 위치 옮길 때마다 시간 계산 + 위치 옮기기 + 초기화
  // 사이즈보다 작은 물고기 count
  while(smallFish.length) {
    if(shortDistFish.length === 0 || shortDistFish[0].dist === 0) break;
    shark.time += visited[shortDistFish[0].y][shortDistFish[0].x];
    shark.y = shortDistFish[0].y;
    shark.x = shortDistFish[0].x;
    shark.eat++;
    map[shark.y][shark.x] = 0;

    fish = fish.filter((el) => {
      return el.y !== shark.y || el.x !== shark.x
    });
    // console.log('shark: ', shark)
    smallFish = smallFish.filter(el => {
      return el.y !== shark.y || el.x !== shark.x
    });
  
    if(shark.eat === shark.size) {
      shark.size++;
      shark.eat = 0;

      smallFish = findSmallFish();
    }
    
    bfs();
    shortDistFish = findShortDistFish(smallFish);
  }
}

eatFish();
console.log(shark.time);
