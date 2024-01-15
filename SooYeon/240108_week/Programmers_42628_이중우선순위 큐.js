function solution(operations) {
  var answer = [];
  let queue = [];
  let idx;
  
  for(let i = 0; i < operations.length; i++) {
      let [op, num] = operations[i].split(' ');
      num = Number(num);

      if(op == 'I') {
          queue.push(num);
      }
      else {
          if(num == -1) {
              // 최솟값 삭제
              if(queue.length == 0) continue;
              idx = queue.indexOf(Math.min.apply(null, queue));
              queue.splice(idx, 1);
          } else {
              // 최댓값 삭제
              if(queue.length == 0) continue;
              idx = queue.indexOf(Math.max.apply(null, queue));
              queue.splice(idx, 1);
          }
      }
  }
  
  if(queue.length == 0) return [0, 0];
  else {
      answer.push(Math.max.apply(null, queue));
      answer.push(Math.min.apply(null, queue));
  }
  
  return answer;
}