let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `2
// 6
// 12`.split('\n');

let testCase = Number(input[0]);

let arr = [];
arr.push(1);
arr.push(1);
arr.push(1);

for(let i = 0; i < 100; i++) {
  arr.push(arr[i] + arr[i + 1]);
}

let answer = [];
for(let i = 1; i <= testCase; i++) {
  let n = Number(input[i]);
  answer.push(arr[n - 1]);
}

console.log(answer.join('\n'));