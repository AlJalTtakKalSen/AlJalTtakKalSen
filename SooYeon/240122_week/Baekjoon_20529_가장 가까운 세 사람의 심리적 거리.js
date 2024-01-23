let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `3
// 3
// ENTJ INTP ESFJ
// 4
// ESFP ESFP ESFP ESFP
// 5
// INFP INFP ESTP ESTJ ISTJ`.split('\n');

let testCase = Number(input[0]);
let mbti = [];

// 조합으로 3명을 뽑아서 
// A와 B의 문자 차이 개수 + B와 C의 문자 차이 개수 + A와 C의 문자 차이 개수가 
// 최소가 되는 경우를 찾는다.

const getDiff = (a, b) => {
  let cnt = 0;
  for(let i = 0; i < 4; i++) {
    if(a[i] != b[i]) cnt++;
  }

  return cnt;
}

let result = 987654321;
const combi = (start, b) => {
  if(b.length == 3) {
    let cnt = 0;
    cnt += getDiff(b[0], b[1]);
    cnt += getDiff(b[1], b[2]);
    cnt += getDiff(b[0], b[2]);

    result = Math.min(result, cnt);
    return;
  }

  for(let i = start + 1; i < mbti.length; i++) {
    b.push(mbti[i]);
    combi(i, b, answer);
    b.pop();
  }
  return;
}

let line = 1;
let answer = [];
for(let t = 1; t <= testCase; t++) {
  let n = Number(input[line]);
  mbti = input[line + 1].split(' ');

  line += 2;
  // 서로 다른 mbti를 가진 16명이 2명씩 총 32명 있을 경우 심리적 거리는 0이 될 수 없음
  // 33명부터 동일한 mbti를 가진 사람이 3명 이상 있을 수 있으므로 0을 출력
  if(n > 32) {
    answer.push(0);
  }
  else {
    combi(-1, []);
    answer.push(result);
    result = 987654321;
  }
}

console.log(answer.join('\n'));