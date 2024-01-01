let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

let n = Number(input[0]);
let INF = 987654321;
let arr = Array.from(Array(n + 1), () => Array(n + 1).fill(INF));
let graph = new Array(n + 1);

for(let i = 1; i <= n; i++) {
  graph[i] = input[i].split('');
  arr[i][i] = 0;
  for(let j = 0; j < n; j++) {
    if(graph[i][j] == 'Y') arr[i][j + 1] = 1;
  }
}

for(let k = 1; k <= n; k++) {
  for(let a = 1; a <= n; a++) {
    for(let b = 1; b <= n; b++) {
      arr[a][b] = Math.min(arr[a][k] + arr[k][b], arr[a][b]);
    }
  }
}

// a에서 b로 가는 최단 경로 확인
let twoFriends = new Array(n + 1).fill(0);
for(let a = 1; a <= n; a++) {
  for(let b = 1; b <= n; b++) {
    // 거리가 2 이하인 노드의 수 세기
    if(a != b && arr[a][b] <= 2) twoFriends[a]++;
  }
}

console.log(Math.max(...twoFriends));
