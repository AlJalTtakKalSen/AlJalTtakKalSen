let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

let [n, m] = input[0].split(' ').map(Number);

let arr = [];
for(let i = 1; i <= n; i++) arr.push(i);

let answer = '';
function combi(start, b) {
  if(b.length === m) {
    for(let i of b) answer += arr[i] + ' ';
    answer += '\n';
    return;
  }

  for(let i = start + 1; i < n; i++) {
    b.push(i);
    combi(i, b);
    b.pop();
  }
  return;
}

let b = [];
combi(-1, b);
console.log(answer);