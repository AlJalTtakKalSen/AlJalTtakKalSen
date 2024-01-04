// 테스트 케이스 16,17 시간초과 못잡음

#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    while (n > 0 && (deliveries[n - 1] == 0 && pickups[n - 1] == 0)) {
                n--;
    }
    
    while(n>0) {
        int delivery = cap;
        int pickup = cap;
        answer += 2 * n;
        
        for(int i = n-1; i >= 0; i--){
            
            if(deliveries[i] <= delivery){
                delivery -= deliveries[i];
                deliveries[i] = 0;
            } else {
                if(delivery > 0){
                    deliveries[i] -= delivery;
                    delivery = 0;
                }
            }
            if(pickups[i] <= pickup){
                pickup -= pickups[i];
                pickups[i] = 0;
            } else {
                if(pickup > 0){
                    pickups[i] -= pickup;
                    pickup = 0;
                }
            }
            
            while (n > 0 && (deliveries[n - 1] == 0 && pickups[n - 1] == 0)) {
                n--;
            }
            
        }
        
    }
  
    return answer;
}