function solution(record) {
    var answer = [];
    
    // 한 번 반복문을 돌아서 아이디-닉네임 쌍을 만들어 놓는다.
    // 다시 반복문을 돌아서 쌍에서 아이디로 닉네임을 불러와 결과 출력
    const map = new Map();
    
    for(let i = 0; i < record.length; i++) {
        let list = record[i].split(' ');
        if(list[0] !== 'Leave') {
            map.set(list[1], list[2]);
        }
    }
    
    for(let i = 0; i < record.length; i++) {
        let str = "";
        let list = record[i].split(' ');
        
        if(list[0] === 'Change') continue;
        str += (map.get(list[1]) + "님이 ");
        
        if(list[0] === 'Enter') str += "들어왔습니다.";
        else if(list[0] === 'Leave') str += '나갔습니다.';
        
        answer.push(str);
    }
    
    return answer;
}
