let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `2
// 5
// 50 10 100 20 40
// 30 50 70 10 60
// 7
// 10 30 10 50 100 20 40
// 20 40 30 50 60 20 80`.split('\n');

let testCase = Number(input[0]);

// 50 max(10+0, 10+30)=40 max(30+100, 100+100)=200 max(100+20, 120+20)=140 max(120+40, 210+40)=250
// 30 max(50+0, 50+50)=100 max(50+70, 40+70)=120 max(40+10, 200+10)=210 max(200+60, 140+60)=260 정답

// 10 max(0+30, 20+30)=50 max(20+10, 50+10)=60 max(50+40, 80+50)=130 max(80+100, 110+100)=210 max(110+20, 190+20)=210 max(190+40, 230+40)=270
// 20 max(0+40, 10+40)=50 max(10+30, 50+30)=80 max(50+50, 60+50)=110 max(60+60, 130+60)=190 max(130+20, 210+20)=230 max(210+80, 210+80)=290 정답

let line = 1;
let answer = [];
let dp;
for(let i = 1; i <= testCase; i++) {
  let n = Number(input[line]);
  let arr = [];
  arr.push(input[line + 1].split(' ').map(Number));
  arr.push(input[line + 2].split(' ').map(Number));

  dp = Array.from(Array(2), () => Array(n + 1).fill(0));

  dp[0][1] = arr[0][0], dp[1][1] = arr[1][0];

  for(let j = 2; j < n + 1; j++) {
    dp[0][j] = Math.max(dp[1][j - 2] + arr[0][j - 1], dp[1][j - 1] + arr[0][j - 1]);
    dp[1][j] = Math.max(dp[0][j - 2] + arr[1][j - 1], dp[0][j - 1] + arr[1][j - 1]);
  }

  answer.push(Math.max(dp[0][n], dp[1][n]));

  line += 3;
}

console.log(answer.join('\n'));