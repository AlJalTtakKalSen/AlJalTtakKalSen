let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `4 10
// 1 2 1 2 1 2 1 2 1 2
// 2 1 2 1 2 1 2 1 2 1
// 1 2 1 2 1 2 1 2 1 2
// 2 1 2 1 2 1 2 1 2 1`.split('\n');

let [n, m] = input[0].split(' ').map(Number);

let arr = [];
let visited = Array.from(Array(n), () => Array(m).fill(false));

for(let i = 1; i <= n; i++) {
  let row = input[i].split(' ').map(Number);
  arr.push(row);
}

let answer = 0;
let dy = [-1, 0, 1, 0];
let dx = [0, 1, 0, -1];

const dfs = (y, x, sum, cnt) => {
  // console.log(y, x, sum, cnt);
  if(cnt == 4) {
    answer = Math.max(answer, sum);
    return;
  }
  
  for(let i = 0; i < 4; i++) {
    let ny = y + dy[i];
    let nx = x + dx[i];

    if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
    if(visited[ny][nx]) continue;

    if(cnt == 2) {
      visited[ny][nx] = true;
      dfs(y, x, sum + arr[ny][nx], cnt + 1);
      visited[ny][nx] = false;
    }

    visited[ny][nx] = true;
    dfs(ny, nx, sum + arr[ny][nx], cnt + 1);
    visited[ny][nx] = false;
  }
}

for(let i = 0; i < n; i++) {
  for(let j = 0; j < m; j++) {
    visited[i][j] = true;
    dfs(i, j, arr[i][j], 1);
    visited[i][j] = false;
  }
}

console.log(answer);