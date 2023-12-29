let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let answer = '';
// function fibonacci(n) {
//   if (n == 0) {
//       answer += '0';
//       return 0;
//   } else if (n == 1) {
//       answer += '1';
//       return 1;
//   } else {
//       return fibonacci(n - 1) + fibonacci(n - 2);
//   }
// }
// fibonacci(5);
// console.log(answer);

let testCase = Number(input[0]);
let arr = Array.from(Array(41), () => Array(3));

arr[0] = [1, 0];
arr[1] = [0, 1];
arr[2] = [1, 1];
arr[3] = [1, 2]; 

for(let i = 4; i < 41; i++) {
  arr[i] = [arr[i-1][0] + arr[i-2][0], arr[i-1][1] + arr[i-2][1]];
}

for(let t = 1; t <= testCase; t++) {
  let n = Number(input[t]);
  console.log(arr[n][0], arr[n][1]);
}
