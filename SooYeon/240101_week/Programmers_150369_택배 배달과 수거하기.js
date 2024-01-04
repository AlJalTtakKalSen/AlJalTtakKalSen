function solution(cap, n, deliveries, pickups) {
    let answer = 0;
    
    // 배달과 수거 중 거리 값이 더 큰 값을 선택
    // 멀리있는 것 부터 확인
    while(deliveries.length || pickups.length) {
        let possible = cap;
        let dist = [0, 0];
        
        // 배달 거리 계산
        // 0인 인덱스는 없애버림
        for(let i = deliveries.length - 1; i >= 0; i--) {
            if(deliveries[i] !== 0) {
                // 거리 더하기
                // 가장 큰 인덱스(거리)로 저장
                if(possible === cap) dist[0] = i + 1;
                
                if(deliveries[i] <= possible) {
                    possible -= deliveries[i];
                    deliveries.pop();
                }
                else {
                    deliveries[i] -= possible;
                    break;
                }
            } 
            else deliveries.pop();
        }
        
        possible = cap; // 수거 계산을 위해 초기화
        
        // 수거 거리 계산
        // 0인 인덱스는 없애버림
        for(let i = pickups.length - 1; i >= 0; i--) {
            if(pickups[i] !== 0) {
                // 거리 더하기
                // 가장 큰 인덱스(거리)로 저장
                if(possible === cap) dist[1] = i + 1;
                
                if(pickups[i] <= possible) {
                    possible -= pickups[i];
                    pickups.pop();
                }
                else {
                    pickups[i] -= possible;
                    break;
                }
            }
            else pickups.pop();
        }
        
        // 배달과 수거 중 거리 값이 더 큰 값을 선택
        answer += Math.max(dist[0], dist[1]) * 2;
    }
    
    return answer;
}
