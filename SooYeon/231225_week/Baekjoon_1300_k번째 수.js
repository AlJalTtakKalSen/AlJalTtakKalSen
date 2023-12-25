let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

let n = Number(input[0]);
let k = Number(input[1]);

let start = 1; // 가장 작은 값
let end = 10 ** 9; // 가장 큰 값

let result = 0;
while(start <= end) {
  let mid = parseInt((start + end) / 2); // 찾고자 하는 B[k]
  let total = 0;
  for(let i = 1; i <= n; i++) {
    total += Math.min(parseInt(mid / i), n); // mid보다 작은 수의 개수
  }
  if(total < k) start = mid + 1;
  else {
    result = mid;
    end = mid - 1;
  }
}

console.log(result);