const getDivisors = (num) => {
  if(num === 1) return 0
  const divisors = [];
  
  for(let i = 1; i <= Math.sqrt(num); i++) {
      if(num % i === 0) {
          divisors.push(i);
          if(num / i <= 1e7 && num / i !== num && num / i !== i) 
              return num / i;
      }
  }
  
  return divisors[divisors.length - 1];
}

function solution(begin, end) {
  let answer = [];
  for(let i = begin; i <= end; i++) {
      answer.push(getDivisors(i));
  }
  
  return answer;
}