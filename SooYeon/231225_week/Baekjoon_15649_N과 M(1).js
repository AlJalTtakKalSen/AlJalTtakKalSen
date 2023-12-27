let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

let [n, m] = input[0].split(' ').map(Number);
let arr = []; // 순열을 계산하고자 하는 원소가 담긴 배열

for(let i = 1; i <= n; i++) {
  arr.push(i);
}

let visited = new Array(n).fill(false); // 방문 여부 배열
let selected = []; // 현재 순열에 포함된 원소
let answer = '';

function dfs(arr, depth) {
  if(depth === m) {
    for(let i of selected) answer += arr[i] + ' ';
    answer += '\n';
    return;
  }

  for(let i = 0; i < arr.length; i++) {
    if(visited[i]) continue; // 이미 방문한 적이 있다면 continue;

    // 백 트래킹 알고리즘
    selected.push(i);
    visited[i] = true;
    dfs(arr, depth + 1);
    selected.pop();
    visited[i] = false;
  }
}

dfs(arr, 0);
console.log(answer);