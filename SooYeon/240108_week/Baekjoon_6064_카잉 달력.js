let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `3
// 10 12 3 9
// 10 12 7 2
// 13 11 5 6`.split('\n');

let testCase = Number(input[0]);

const gcd = (a, b) => {
  let r = b;
  while(r !== 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

const calendar = (m, n, x, y, max_rotate) => {
  let cal_y = y;

  for(let i = x; i <= max_rotate; i += m) {
    cal_y = i % n;
    if(n == y) {
      if(i % n == 0) return i;
    }
    if(cal_y == y) {
      if(i % n == y) return i;
    }
  }

  return -1;
}

let answer = '';
for(let i = 1; i <= testCase; i++) {
  let [m, n, x, y] = input[i].split(' ').map(Number);
  let max_rotate = (m * n) / gcd(m, n);

  if(x == m && y == n) {
    answer += max_rotate + '\n';
  } else {
    answer += calendar(m, n, x, y, max_rotate) + '\n';
  }
}

answer = answer.slice(0, answer.length - 1);
console.log(answer);