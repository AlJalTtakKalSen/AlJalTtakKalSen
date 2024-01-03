function solution(t, p) {
    var answer = 0;
    let arr = [];
    
    for(let i = 0; i <= t.length - p.length; i++) {
        let number = '';
        
        for(let j = i; j < p.length + i; j++) {
            number += t[j]
        }
        if(Number(number) <= Number(p)) { 
            arr.push(number);
        }
    }
    
    answer = arr.length
    
    return answer;
}
