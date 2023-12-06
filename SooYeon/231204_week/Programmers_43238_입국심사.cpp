#include <bits/stdc++.h>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    // 입국 심사에 가장 오래 걸리는 심사관을 알기 위해 정렬 [오름차순]
    sort(times.begin(), times.end());
    
    // 입국 심사에 걸리는 시간의 최소값이 1분이기 때문에 시작을 1분으로
    // 입국 심사에 걸리는 시간의 최대값은 정렬한 리스트의 마지막 인덱스 값
    long long start = 1;
    long long end = (long long)times[times.size()-1] * n;
    long long mid;
    
    while(start <= end) {
        long long cnt = 0;
        mid = (start + end) / 2;
        
        // mid 시간 동안 처리할 수 있는 사람 수++
        for(int time: times) {
            cnt += mid / time;
        };
        
        // 만약 처리할 수 있는 사람의 수가 입국 심사를 기다리는 사람보다 많다면
        if(cnt >= n) {
            // 답이 될 수도 있으니 answer에 저장
            if(mid <= end) answer = mid;
            // end 값을 줄여서 재실행
            end = mid - 1;
        }
        else {
            start = mid + 1;
        };
    };
    
    return answer;
}
