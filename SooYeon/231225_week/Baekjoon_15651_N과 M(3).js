let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

let [n, m] = input[0].split(' ').map(Number);
let arr = [];
for(let i = 1; i <= n; i++) arr.push(i);

// 중복 조합
let answer = '';
function combi(start, b) {
  if(b.length === m) {
    for(let i of b) answer += arr[i] + ' ';
    answer += '\n';
    return;
  }

  for(let i = 0; i < n; i++) {
    b.push(i);
    combi(i, b);
    b.pop();
  }
  return;
}

let b = [];
combi(0, b); // combi 함수 안 백트래킹 알고리즘 반복문에서 재귀함수 호출 시 start가 증가하지 않으므로 0부터
console.log(answer);