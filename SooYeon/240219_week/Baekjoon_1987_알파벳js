let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `5 5
// IEFCJ
// FHFKC
// FFALF
// HFGCF
// HMCHH`.split('\n');

let [r, c] = input[0].split(' ').map(Number);
let board = input.slice(1).map((v) => v.split(''));
let visited = new Array(26).fill(false);
let dy = [-1, 0, 1, 0];
let dx = [0, 1, 0, -1];

let answer = 0;

const dfs = (y, x, cnt) => {
  answer = Math.max(answer, cnt);
  
  for(let i = 0; i < 4; i++) {
    let ny = y + dy[i];
    let nx = x + dx[i];
    
    if(ny >= r || ny < 0 || nx >= c || nx < 0) continue;
    if(visited[board[ny][nx].charCodeAt() - 65]) continue;
    
    visited[board[ny][nx].charCodeAt() - 65] = true;
    dfs(ny, nx, cnt + 1);
    visited[board[ny][nx].charCodeAt() - 65] = false;
  }
}

visited[board[0][0].charCodeAt() - 65] = true;
dfs(0, 0, 1);
console.log(answer);