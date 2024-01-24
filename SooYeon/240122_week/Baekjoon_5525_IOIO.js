let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `2
// 13
// OOIOIOIOIIOII`.split('\n');

let n = Number(input[0]);
let m = Number(input[1]);
let s = input[2];

let cnt = 0, answer = 0;
for(let i = 1; i < m - 1; i++) {
  if(s[i - 1] == 'I' && s[i] == 'O' && s[i + 1] == 'I') {
    cnt++;

    if(cnt == n) {
      answer++;
      cnt--;
    }
    i++;
  } else {
    cnt = 0;
  }
}

console.log(answer);