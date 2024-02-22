let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trimEnd().split('\n');

// let input = `2 2
// 1000 1000
// 1000 1000`.split('\n');

let [n, b] = input[0].split(' ').map(Number);
let matrix = input.splice(1).map((el) => el.split(' ').map(Number));

const multiply = (a, b) => {
  let temp = Array.from(Array(n), () => Array(n).fill(0));

  for(let i = 0; i < n; i++) {
    for(let j = 0; j < n; j++) {
      for(let k = 0; k < n; k++) {
        temp[i][j] += a[i][k] * b[k][j];
      }
      temp[i][j] %= 1000;
    }
  }
  return temp;
}

const pow = (a, b) => {
  if(b === 1) {
    a.forEach((el, i) => el.forEach((_, j) => a[i][j] %= 1000));
    return a;
  }
  if(b % 2) {
    return multiply(a, pow(a, b - 1));
  } else {
    let temp = pow(a, b / 2);
    return multiply(temp, temp);
  }
}

let answer = pow(matrix, b);
console.log(answer.map((el) => el.join(' ')).join('\n'));