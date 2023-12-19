function solution(a, b) {
    var answer = 1234567890;
    
    let temp = 0;
    for(let i = 0; i < a.length; i++) {
        temp += a[i] * b[i];
    }
    
    answer = temp;
    
    return answer;
}
