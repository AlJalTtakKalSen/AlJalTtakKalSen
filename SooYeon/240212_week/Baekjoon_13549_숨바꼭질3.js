let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `5 17`.split('\n');

let [n, k] = input[0].split(' ').map(Number);
let visited = new Array(100000).fill(false);

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

const bfs = (n) => {
  let queue = new Queue;
  queue.push({locate: n, time: 0});

  while(queue.size()) {
    let cur = queue.front();
    queue.pop();

    if(cur.locate === k) {
      return cur.time;
    }

    // 순간이동을 하는 경우
    if(cur.locate * 2 <= 100000 && !visited[cur.locate * 2]) {
      visited[cur.locate * 2] = true;
      queue.push({locate: cur.locate * 2, time: cur.time});
    }
    // 뒤로 한 칸 이동하는 경우, 1초 걸림
    if(cur.locate - 1 >= 0 && !visited[cur.locate - 1]) {
      visited[cur.locate - 1] = true;
      queue.push({locate: cur.locate - 1, time: cur.time + 1});
    }
    // 앞으로 한 칸 이동하는 경우, 1초 걸림
    if(cur.locate + 1 <= 100000 && !visited[cur.locate + 1]) {
      visited[cur.locate + 1] = true;
      queue.push({locate: cur.locate + 1, time: cur.time + 1});
    }
  }
}

console.log(bfs(n));