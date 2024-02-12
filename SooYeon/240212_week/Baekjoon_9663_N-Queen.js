let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `8`.split('\n');

// 같은 행, 열, 대각선 방향으로는 퀸을 놓을 수 없음
let n = Number(input[0]);
let queens = []; // 퀸이 놓인 위치 저장

const isPossible = (row, col) => {
  for(let [r, c] of queens) {
    // 같은 행, 열에 놓을 수 없음
    if(r === row || c === col) return false;
    // 같은 대각선에 놓을 수 없음
    if(Math.abs(r - row) === Math.abs(c - col)) return false;
  }
  return true;
}

let cnt = 0;
const dfs = (row) => {
  if(row === n) {
    // 퀸을 n개 놓았다면 방법 1개 추가
    cnt++;
    return;
  }

  for(let i = 0; i < n; i++) {
    if(isPossible(row, i)) {
      queens.push([row, i]);
      dfs(row + 1); // 다음 줄 확인
      queens.pop();
    }
  }
}

// 첫 번째 줄부터 시작
dfs(0);
console.log(cnt);