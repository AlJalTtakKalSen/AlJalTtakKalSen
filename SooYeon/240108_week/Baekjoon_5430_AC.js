let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `4
// RDD
// 4
// [1,2,3,4]
// DD
// 1
// [42]
// RRD
// 6
// [1,1,2,3,5,8]
// D
// 0
// []`.split('\n');

// R: 배열에 있는 수의 순서를 뒤집는 함수
// D: 첫 번째 수를 버리는 함수 (빈 배열일 경우 무시)
let testCase = Number(input[0]);
let line = 1;

const D = (arr, isReverse) => {
  if(isReverse) arr.pop();
  else arr.shift();

  return arr;
}

let answer = '';
for(let t = 0; t < testCase; t++) {
    let p = input[line].split('');
    let n = Number(input[line + 1]);

    let arr = JSON.parse(input[line + 2]);
    if(arr.length === 1 && arr[0] === 0) {
      arr = [];
    }

    let tmp = '[';
    let isReverse = false;
    for(let i = 0; i < p.length; i++) {
      if(p[i] == 'R') {
        isReverse = !isReverse;
      } else {
        if(arr.length == 0) {
          tmp = 'error';
          break;
        }
        arr = D(arr, isReverse);
      }
    }

    if(isReverse) arr.reverse();
    if(tmp !== 'error') {
      let result = arr.join(',');
      tmp += result;
      tmp += ']';
    }
    
    if(t !== testCase - 1) answer += tmp + '\n';
    else answer += tmp;

  line += 3;
}

console.log(answer);