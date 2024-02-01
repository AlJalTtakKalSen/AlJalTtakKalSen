let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `3 1
// 4 4 2`.split('\n');

let [n, m] = input[0].split(' ').map(Number);
let numbers = input[1].split(' ').map(Number);

numbers.sort((a, b) => a - b);

let answer = [];
const combi = (start, b) => {
  if(b.length == m) {
    let tmp = [];
    b.forEach((num) => tmp.push(numbers[num]));
    answer.push([...tmp]);
    return;
  }

  for(let i = 0; i < n; i++) {
    if(b.includes(i)) continue;
    b.push(i);
    combi(i, b);
    b.pop();
  }
  return;
}

combi(0, []);
answer = new Set(answer.map((arr) => arr.join(' ')));
console.log([...answer].join('\n'));