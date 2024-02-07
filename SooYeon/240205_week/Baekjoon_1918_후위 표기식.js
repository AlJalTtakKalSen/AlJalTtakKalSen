let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `A+B*C-D/E`.split('\n');
let expression = input[0].split('');
let stack = [];

// 우선순위는 *, / -> +, -
// 스택에서 위로 갈 수록 우선순위가 높아짐. 즉, pop 되는 것도 우선순위가 높은 것부터 pop 된다.

// *나 /를 만나면 stack에서 '+'나 '-'나 '('가 아닌게 top인 동안은 쭉 뽑아주고,
// +나 -를 만나면 stack에서 '('가 아닌 게 top인 동안은 쭉 뽑아주고,
// '('는 그냥 push, ')'은 stack에서 ')'가 top일 때까지 쭉 뽑는다.
// 숫자는 그때그때 출력

let answer = '';
for(let i = 0; i < expression.length; i++) {
  if(expression[i] === '*' || expression[i] === '/') {
    // 스택의 위에 *나 /가 있으면 그 두개가 우선순위가 더 높기 때문에 먼저 처리해야 함.
    // 처리한 후에 현재 연산자를 스택에 push
    while(stack.length && stack[stack.length - 1] === '*' || stack[stack.length - 1] === '/') {
      answer += stack.pop();
    }
    stack.push(expression[i]);
  }
  else if(expression[i] === '+' || expression[i] === '-') {
    // 우선순위가 가장 낮기 때문에 스택에 있는 연산자들을 pop 한 후에 현재 연산자를 push
    // ( 안의 연산자일 수도 있으므로 (가 나올 때까지만 pop
    while(stack.length && stack[stack.length - 1] !== '(') {
      answer += stack.pop();
    }
    stack.push(expression[i]);
  }
  else if(expression[i] === '(') {
    stack.push(expression[i]);
  }
  else if(expression[i] === ')') {
    // (가 나올 때까지 pop
    while(stack.length && stack[stack.length - 1] !== '(') {
      answer += stack.pop();
    }
    // ( 연산자 pop
    stack.pop();
  }
  else {
    // 피연산자는 그대로 더하기
    answer += expression[i];
  }
}

// 스택에 남아있는 연산자들 그대로 더하기
// 어차피 스택의 위로 갈 수록 우선순위가 높기 때문에 그냥 다 더해주면 됨.
while(stack.length) {
  answer += stack.pop();
}

console.log(answer);