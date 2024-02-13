let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `4 7
// 6 13
// 4 8
// 3 6
// 5 12`.split('\n');

let [n, k] = input[0].split(' ').map(Number);
let arr = input.slice(1).map(v => v.split(' ').map(Number));
let dp = Array.from({length: n + 1}, () => Array(k + 1).fill(0));

// n번만큼 반복
for(let i = 1; i <= n; i++) {
  let [w, v] = arr[i - 1];
  // k번 만큼 반복 (무게를 1씩 증가시키면서 확인)
  for(let j = 1; j <= k; j++) {
    // 현재 물건을 넣을 수 없는 경우, 이전 물건의 최대 가치를 그대로 가져옴
    if(j < w) dp[i][j] = dp[i - 1][j];
    // 현재 물건을 넣을 수 있는 경우, 
    // 이전 물건의 최대 가치와 현재 물건을 넣었을 때의 최대 가치 중 큰 값을 선택
    else {
      dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - w] + v)
    }
  }
}

console.log(dp[n][k]);