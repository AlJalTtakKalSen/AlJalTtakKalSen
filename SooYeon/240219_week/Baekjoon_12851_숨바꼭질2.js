let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `5 17`.split('\n');

let [n, k] = input[0].split(' ').map(Number);
let arr = new Array(100001).fill(0);
let visited = new Array(100001).fill(0);

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

let q = new Queue();
q.push([n, 0]);
let count = {time: 0, count: 0};

while(q.size()) {
  let [cur, time] = q.front();
  q.pop();

  visited[cur] = 1;

  if(cur === k) {
    if(count.time === 0) {
      count.time = time;
      count.count++;
    } else {
      if(count.time === time) count.count++;
      else break;
    }
  }

  if(cur - 1 >= 0 && !visited[cur - 1]) {
    q.push([cur - 1, time + 1]);
  }
  if(cur + 1 < 100001 && !visited[cur + 1]) {
    q.push([cur + 1, time + 1]);
  }
  if(cur * 2 < 100001 && !visited[cur * 2]) {
    q.push([cur * 2, time + 1]);
  }
}

console.log(count.time + '\n' + count.count);