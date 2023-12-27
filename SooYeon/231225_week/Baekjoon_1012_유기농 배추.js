let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

let dy = [-1, 0, 1, 0];
let dx = [0, 1, 0, -1];

let testCase = Number(input[0]);
let arr, visited; 
let m, n, k;

function dfs(y, x) {
  visited[y][x] = true;

  for(let i = 0; i < 4; i++) {
    let ny = y + dy[i];
    let nx = x + dx[i];

    if(ny >= n || ny < 0 || nx >= m || nx < 0) continue;
    if(!arr[ny][nx] || visited[ny][nx]) continue;
    
    dfs(ny, nx);
  }
}

let line = 2;
for(let t = 0; t < testCase; t++) {
  let answer = 0;
  [m, n, k] = input[line - 1].split(' ').map(Number);

  arr = Array.from(Array(51), () => Array(51).fill(0));
  visited = Array.from(Array(51), () => Array(51).fill(false));
  
  for(let i = line; i < line + k; i++) {
    let [x, y] = input[i].split(' ').map(Number);
    arr[y][x] = 1;
  }

  for(let i = 0; i < n; i++) {
    for(let j = 0; j < m; j++) {
      if(arr[i][j] && !visited[i][j]) {
        answer++;
        dfs(i, j);
      }
    }
  }

  line += k + 1;
  console.log(answer);
}