let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `24`.split('\n');

let n = Number(input[0]);

let star = [];
for(let i = 0; i < n; i++) {
  star[i] = Array(n * 2).fill(' ');
}

const draw = (y, x, n) => {
  if(n === 3) {
    star[y][x] = '*';
    star[y + 1][x - 1] = '*';
    star[y + 1][x + 1] = '*';
    star[y + 2][x - 2] = '*';
    star[y + 2][x - 1] = '*';
    star[y + 2][x] = '*';
    star[y + 2][x + 1] = '*';
    star[y + 2][x + 2] = '*';
    return;
  }

  draw(y, x, n / 2);
  draw(y + n / 2, x - n / 2, n / 2);
  draw(y + n / 2, x + n / 2, n / 2);
}

draw(0, n - 1, n);
console.log(star.map((el) => el.join('')).join('\n'));