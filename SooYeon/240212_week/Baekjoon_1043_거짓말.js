let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `9 4
// 1 1
// 4 1 2 3 4
// 4 5 6 7 8
// 2 8 9
// 2 4 9`.split('\n');

// n: 사람의 수, m: 파티의 수
let [n, m] = input[0].split(' ').map(Number);
let knowTruth = input[1].split(' ').map(Number);
let truthPeople = knowTruth.slice(1); // 진실을 아는 사람들
knowTruth = knowTruth[0]; // 진실을 아는 사람의 수

let party = input.slice(2).map(e => e.split(' ').map(Number));
let truth = new Array(m).fill(false); // 진실을 아는 파티인지 확인하는 배열
let queue = [];

// 진실을 아는 사람들을 모두 true로 바꿔줌
for(let i = 0; i < m; i++) {
  for(let j = 1; j <= party[i][0]; j++) {
    if(truthPeople.includes(party[i][j])) {
      truth[i] = true;

      queue.push(i);
      break;
    }
  }
}

while(queue.length) {
  let cur = queue.shift();
  let curPartyArr = party[cur].slice(1);

  for(let i = 0; i < m; i++) {
    for(let j = 1; j <= party[i][0]; j++) {
      if(!truth[i] && curPartyArr.includes(party[i][j])) {
        truth[i] = true;
        queue.push(i);
      }
    }
  }
}

let answer = 0;
for(let i = 0; i < truth.length; i++) {
  if(!truth[i]) answer++;
}

console.log(answer);
