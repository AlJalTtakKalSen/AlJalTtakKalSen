let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `100 40021`.split('\n');

let [a, b] = input[0].split(' ').map(Number);

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

let queue = new Queue();
let visited = new Set();
let answer = -1;
queue.push([a, 1]);
visited.add(a);

while(queue.size()) {
  let [num, cnt] = queue.front();
  queue.pop();

  if(num == b) {
    answer = cnt;
    break;
  }
  
  if(num * 2 <= b && !visited.has(num * 2)) {
    queue.push([num * 2, cnt + 1]);
    visited.add(num * 2);
  }
  if(num * 10 + 1 <= b && !visited.has(num * 10 + 1)) {
    queue.push([num * 10 + 1, cnt + 1]);
    visited.add(num * 10 + 1);
  }
}

console.log(answer);