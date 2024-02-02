let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `4 2
// 9 7 9 1`.split('\n');

let [n, m] = input[0].split(' ').map(Number);
let arr = input[1].split(' ').map(Number);

arr.sort((a, b) => a - b);

let answer = [];
const combi = (start, b) => {
  if(b.length == m) {
    let tmp = [];
    b.forEach((num) => tmp.push(arr[num]));
    answer.push([...tmp]);
    return;
  }

  for(let i = start; i < n; i++) {
    b.push(i);
    combi(i, b);
    b.pop();
  }
  return;
}

combi(0, []);
answer = new Set(answer.map((arr) => arr.join(' ')));
console.log([...answer].join('\n'));