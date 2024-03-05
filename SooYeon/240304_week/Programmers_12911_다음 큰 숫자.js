function makeBinary(value) {
  let binary = '';
  let oneCnt = 0;
  
  while(value) {
      let bit = Math.floor(value % 2);
      if(bit === 1) oneCnt++;
      binary = bit + binary;
      value = Math.floor(value / 2);
  }
  
  return oneCnt;
}

function solution(n) {
  let answer = 0;
  
  // n을 2진수로 변경
  let n_oneCnt = makeBinary(n);
  
  let nextBigNum = n + 1;
  while(true) {
      let nextBigNum_oneCnt = makeBinary(nextBigNum);
      if(n_oneCnt === nextBigNum_oneCnt) {
          answer = nextBigNum;
          break;
      }
      nextBigNum++;
  }
  
  
  return answer;
}