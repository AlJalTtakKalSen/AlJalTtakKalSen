function solution(land) {
  let answer = 0;
  let dp = Array.from(Array(land.length), () => Array(4).fill(0));
  
  for(let i = 0; i < 4; i++) {
      dp[0][i] = land[0][i];
  }
  
  for(let i = 1; i < land.length; i++) {
      for(let j = 0; j < 4; j++) {
          for(let k = 0; k < 4; k++) {
              if(j === k) continue;
              dp[i][k] = Math.max(dp[i-1][j] + land[i][k], dp[i][k]);
          }
      }
  }
  
  // console.log(dp);
  
  answer = Math.max(...dp[land.length - 1]);
  
  return answer;
}