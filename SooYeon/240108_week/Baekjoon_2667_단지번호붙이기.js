let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `7
// 0110100
// 0110101
// 1110101
// 0000111
// 0100000
// 0111110
// 0111000`.split('\n');

let dy = [-1, 0, 1, 0];
let dx = [0, 1, 0, -1];

let n = Number(input[0]);
let arr = [];
let visited = Array.from(Array(n), () => Array(n).fill(false));
let apartmentCntArr = [];

for(let i = 1; i <= n; i++) {
  arr.push(input[i].split('').map(Number));
}

let dfs = (y, x) => {
  visited[y][x] = true;
  let cnt = 1;

  for(let i = 0; i < 4; i++) {
    let ny = y + dy[i];
    let nx = x + dx[i];

    if(ny >= n || ny < 0 || nx >= n || nx < 0) continue;
    if(arr[ny][nx] == 0 || visited[ny][nx]) continue;

    cnt += dfs(ny, nx);
  }
  return cnt;
}

for(let i = 0; i < n; i++) {
  for(let j = 0; j < n; j++) {
    if(arr[i][j] && !visited[i][j]) {
      let apartmentCnt = dfs(i, j);
      apartmentCntArr.push(apartmentCnt);
    }
  }
}

apartmentCntArr.sort((a, b) => a - b); // 오름차순 정렬

let answer = '' + apartmentCntArr.length + '\n';
answer += apartmentCntArr.join('\n');

console.log(answer);