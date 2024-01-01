let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

let n = Number(input[0]);
let arr = input[1].split(' ').map(Number);

// 오름차순 정렬
arr.sort((a, b) => a - b);

(0 + 3) + (3 + 1) + (4 + 4) + (8 + 3) + (11 + 2)

let answer = 0, wait = 0;
for(let i = 0; i < arr.length; i++) {
  wait += arr[i];
  answer += wait; 
}

console.log(answer);