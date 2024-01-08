let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `5 3
// 5 4 3 2 1
// 1 3
// 2 4
// 5 5`.split('\n');

// 누적합 알고리즘
let [n, m] = input[0].split(' ').map(Number);
let arr = [0];
input[1].split(' ').forEach((num) => arr.push(Number(num) + arr[arr.length - 1]));

let answer = '';
for(let i = 2; i < m + 2; i++) {
  let [start, end] = input[i].split(' ').map(Number);
  if(i == m + 1) answer += arr[end] - arr[start - 1];
  else answer += arr[end] - arr[start - 1] + '\n';
}
console.log(answer);
