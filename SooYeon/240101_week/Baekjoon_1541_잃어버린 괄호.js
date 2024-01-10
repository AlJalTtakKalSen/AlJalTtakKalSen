let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// 뺼셈 연산자를 기준으로 나누기
let groups = input[0].split('-');

// 뺄셈 연산자를 기준으로 나누어진 그룹들을 모두 더하기 (덧셈 연산자이므로)
let answer = 0;
for(let i = 0; i < groups.length; i++) {
  let group = groups[i].split('+').map(Number).reduce((a, b) => a + b);
  if(i == 0) answer += group; // 첫 번째 그룹은 항상 더하기 (연산자가 없으므로)
  else answer -= group; // 덧셈 연산자로 이어져 있는 값들을 모두 더한 후 마이너스 괄호로 묶기
}

console.log(answer);