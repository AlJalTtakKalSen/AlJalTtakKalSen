function solution(board) {
  for(let i = 0; i < board.length - 1; i++) {
      for(let j = 0; j < board[0].length - 1; j++) {
          if(board[i + 1][j + 1] === 0) continue;
          let leftTop = board[i][j];
          let left = board[i + 1][j];
          let top = board[i][j + 1];
          
          let min = Math.min(Math.min(leftTop, left), top);
          board[i + 1][j + 1] = min + 1;
      }
  }
  
  let answer = 0;
  for(let i = 0; i < board.length; i++) {
      for(let j = 0; j < board[0].length; j++) {
          answer = Math.max(board[i][j], answer);
      }
  }
  
  // console.log(answer * answer);

  return answer * answer;
}