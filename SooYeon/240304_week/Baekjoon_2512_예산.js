// let fs = require("fs");
// let input = fs.readFileSync("/dev/stdin").toString().split("\n");

let input = `3
2 2 2
5`.split("\n");

let n = Number(input[0]);
let arr = input[1].split(" ").map(Number);
let m = Number(input[2]);

let min = Math.min(...arr);
let max = Math.max(...arr);

let left = 1;
let right = max;

while (left <= right) {
  let mid = Math.floor((left + right) / 2);

  let cal = arr.reduce((acc, cur) => {
    if (cur > mid) return acc + mid;
    else return acc + cur;
  }, 0);

  if (cal <= m) left = mid + 1;
  else right = mid - 1;
}

console.log(right);
