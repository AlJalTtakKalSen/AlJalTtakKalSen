let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `11
// 1 4 1 2 4 2 4 2 3 4 4
// 5`.split('\n');

let n = Number(input[0]);
let arr = input[1].split(' ').map(Number);
let v = Number(input[2]);

arr = arr.filter((num) => num == v);

console.log(arr.length);