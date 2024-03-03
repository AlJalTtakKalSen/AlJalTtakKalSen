function solution(n) {
  let answer = '';
  let value = [4, 1, 2];
  
  while(n) {
      answer = value[n % 3] + answer;
      n = n % 3 === 0 ? Math.floor((n - 1) / 3) : Math.floor(n / 3);
  }
  
  return answer;
}