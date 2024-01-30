// let fs = require('fs');
// let input = fs.readFileSync('/dev/stdin').toString().split('\n');

let input = `4 3
1 2 3 4
2 3 4 5
3 4 5 6
4 5 6 7
2 2 3 4
3 4 3 4
1 1 4 4`.split('\n');

let [n, m] = input[0].split(' ').map(Number);

let arr = [], d = Array.from(Array(n + 1), () => Array(n + 1).fill(0)), answer = [];
for(let i = 1; i <= n; i ++) {
  arr.push(input[i].split(' ').map(Number));

  for(let j = 1; j <= n; j++) {
    d[i][j] = arr[i-1][j-1];
  }
}

for(let i = 1; i <= n; i++) {
  for(let j = 1; j <= n; j++) {
    d[i][j] += d[i][j-1];
  }
}

for(let i = 1; i <= n; i++) {
  for(let j = 1; j <= n; j++) {
    d[j][i] += d[j-1][i];
  }
}

for(let i = n + 1; i <= n + m; i++) {
  let [x1, y1, x2, y2] = input[i].split(' ').map(Number);

  answer.push(d[x2][y2] - d[x1 - 1][y2] - d[x2][y1 - 1] + d[x1 - 1][y1 - 1]);
}

console.log(answer.join('\n'));