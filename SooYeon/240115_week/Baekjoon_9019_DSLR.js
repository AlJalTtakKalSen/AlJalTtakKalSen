let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `3
// 1234 3412
// 1000 1
// 1 16`.split('\n');

// D: 2n mod 10000 (mod -> 9999보다 큰 경우)
// S: n-1 (n이 0이면 9999)
// L: n의 각 자릿수를 왼편으로 회전 (shift)
// R: n의 각 자릿수를 오른편으로 회전 (unshift)

let testCase = Number(input[0]);

let answer = [];
const bfs = (a, b) => {
  let queue = [[a, '']];
  let visited = Array(10000).fill(false);
  visited[a] = true;
  while(queue.length) {
    let [value, command] = queue.shift();

    if(value == b) {
      answer.push(command);
      return;
    }

    for(let oper of ['D', 'S', 'L', 'R']) {
      let nextValue;
      if(oper == 'D') nextValue = (value * 2) % 10000;
      if(oper == 'S') nextValue = value === 0 ? 9999 : value - 1;
      if(oper == 'L') nextValue = (value % 1000) * 10 + Math.floor(value / 1000);
      if(oper == 'R') nextValue = (value % 10) * 1000 + Math.floor(value / 10);

      if(!visited[nextValue]) {
        visited[nextValue] = true;
        queue.push([nextValue, command + oper]);
      }
    }
  }
}

for(let i = 1; i <= testCase; i++) {
  let [a, b] = input[i].split(' ').map(Number);
  bfs(a, b);
}

console.log(answer.join('\n'));