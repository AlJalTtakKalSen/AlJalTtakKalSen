function solution(sizes) {
    var answer = 0;
    
    // min max 알고리즘
    let big_num = 0;
    
    for(let i = 0; i < sizes.length; i++) {
        if(sizes[i][0] > big_num) {
            big_num = sizes[i][0];
        }
            
        if(sizes[i][1] > big_num) {
            big_num = sizes[i][1];
        }
    }
   
    let temp = 0, result = 0;
    for(let i = 0; i < sizes.length; i++) {
        sizes[i][0] < sizes[i][1] ? temp = sizes[i][0] : temp = sizes[i][1];
        result = result < temp ? temp : result;
    }
    
    answer = big_num * result;

    return answer;
}
