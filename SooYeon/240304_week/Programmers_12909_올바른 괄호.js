function solution(s){
  let answer = true;

  let stack = [];
  for(let i = 0; i < s.length; i++) {
      if(s[i] === '(') {
          stack.push(s[i]);
      } 
      else {
          if(stack[stack.length - 1] === '(') {
              stack.pop();
          } else {
              answer = false;
              break;
          }
      }
  }
  
  if(stack.length) answer = false;

  return answer;
}