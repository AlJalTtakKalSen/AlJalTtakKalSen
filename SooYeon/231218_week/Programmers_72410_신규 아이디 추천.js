function solution(new_id) {
    var answer = '';
    
    // 1단계
    new_id = new_id.toLowerCase();
    
    // 2단계
    for(let i = 0; i < new_id.length; i++) {
        if((new_id[i] >= 'a' && new_id[i] <= 'z') || new_id[i] === '-' || new_id[i] === '_' || new_id[i] === '.' || (new_id[i] >= '0' && new_id[i] <= '9')) {
            answer += new_id[i];
        }
    }
    
    // 3단계, g플래그: 문자열 전체에서 모든 패턴을 찾도록
    answer = answer.replace(/\.+/g, '.');
    
    // 4단계
    if(answer[0] === '.') {
        answer = answer.slice(1, answer.length);
    }
    if(answer[answer.length - 1] === '.') {
        answer = answer.slice(0, answer.length - 1);
    }
    
    // 5단계
    if(answer === '') answer += 'a';
    
    // 6단계
    if(answer.length > 15) {
        answer = answer.slice(0, 15);
        if(answer[answer.length - 1] === '.')
            answer = answer.slice(0, answer.length - 1);
    }
    
    while(answer.length < 3) {
        answer += answer[answer.length - 1];
    }
    
    return answer;
}
