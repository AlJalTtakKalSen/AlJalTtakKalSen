let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

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

let [n, k] = input[0].split(' ').map(Number);
let visited = new Array(100001).fill(0);

let queue = new Queue();
queue.push(n);
visited[n] = 1;

while(queue.size()) {
  let node = queue.front();
  queue.pop();

  if(node == k) {
    console.log(visited[node] - 1);
    break;
  }

  for(let next of [node - 1, node + 1, node * 2]) {
    if(next >= 100001 || next < 0) continue;
    if(visited[next]) continue;

    queue.push(next);
    visited[next] = visited[node] + 1;
  }
}
