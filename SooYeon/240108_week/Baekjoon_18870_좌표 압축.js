let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `6
// 1000 999 1000 999 1000 999`.split('\n');

let n = Number(input[0]);
let arr = new Set();

// 중복 제거하여 Set에 저장
let tmp = input[1].split(' ').map(Number);
tmp.forEach(item => arr.add(item));

// Set을 배열로 변환
arr = Array.from(arr);
arr.sort((a, b) => a - b); // 오름차순 정렬

let obj = {};
arr.forEach((item, idx) => obj[item] = idx); // 배열의 값과 인덱스를 객체에 저장

let answer = '';
// indexOf는 시간초과가 뜸
for(let i = 0; i < n; i++) {
  let idx = obj[tmp[i]];

  if(i == n - 1) answer += idx;
  else answer += idx + ' ';
}

console.log(answer);