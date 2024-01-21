let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `4 9
// 8 52
// 6 80
// 26 42
// 2 72
// 51 19
// 39 11
// 37 29
// 81 3
// 59 5
// 79 23
// 53 7
// 43 33
// 77 21`.split('\n');

let [n, m] = input[0].split(' ').map(Number);

// 주사위 i + 4 -> 
// 1 + 4/ 2 + 4/ 3 + 4/ 4 + 4/ 5 + 4/ 6 + 4

let ladder = {};
let snake = {};

for(let i = 1; i <= n; i++) {
  let [from, to] = input[i].split(' ').map(Number);
  ladder[from] = to;
}

for(let i = n + 1; i <= n + m; i++) {
  let [from, to] = input[i].split(' ').map(Number);
  snake[from] = to;
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

let answer = 0;
let visited = new Array(101).fill(false);
let queue = new Queue();
queue.push([1, 0]);
visited[1] = true;

while(queue.size()) {
  let [cur, cnt] = queue.front();
  queue.pop();

  if(cur == 100) {
    answer = cnt;
    break;
  }

  if(ladder[cur]) {
    cur = ladder[cur];
  } 
  else if(snake[cur]) {
    cur = snake[cur];
  }

  for(let i = 1; i <= 6; i++) {
    let next = cur + i;
    if(next <= 100 && !visited[next]) {
      visited[next] = true;
      queue.push([next, cnt + 1]);
    }
  }
}

console.log(answer);