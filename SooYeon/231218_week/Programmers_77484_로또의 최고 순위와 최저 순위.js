function solution(lottos, win_nums) {
    var answer = [];
    
    let match_idx = []; // idx
    let zero_cnt = 0, match_cnt = 0;
    
    for(let i = 0; i < lottos.length; i++) {
        if(lottos[i] === 0) {
            zero_cnt++;
            continue;
        }
        
        let idx = win_nums.indexOf(lottos[i]);
        if(idx >= 0) {
            match_cnt++;
            match_idx.push(idx);
        }
    }
    

    // 최고 순위는 0들을 모두 당첨 번호로 바꾸는 것 -> 7 - match_idx + zero_cnt
    let high = 7 - (match_cnt + zero_cnt);
    if(high > 6) high = 6;
    answer.push(high);
        
    // 최저 순위는 0들이 모두 안맞는 것 ->  7 - match_idx
    let low = 7 - match_idx.length;
    if(low > 6) low = 6;
    answer.push(low);

    
    return answer;
}
