function solution(left, right) {
    var answer = 0;
    
    for(let i = left; i <= right; i++) {
        let divisors = [];
        for(let j = 1; j <= Math.sqrt(i); j++) {
            if(i % j === 0) {
                divisors.push(j);
                if((i / j) !== j) divisors.push(i / j);
            }
        }
        if(divisors.length % 2) {
            answer -= i;
        } else {
            answer += i;
        }
    }
    
    return answer;
}
