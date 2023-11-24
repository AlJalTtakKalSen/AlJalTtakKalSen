#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int t = bandage[0];
    int x = bandage[1];
    int y = bandage[2];
    
    int attack_ptr = 0;
    int bandaged_time=0;
    int max_health=health;
    for(int i=1;i<=attacks[attacks.size()-1][0];i++){ // 초
        if (attacks[attack_ptr][0]== i){
            health -= attacks[attack_ptr++][1];
            if (health<=0){
                health = -1; 
                break;
            }
            bandaged_time=0;
        }
        else {
            health+=x;
            bandaged_time++;
            if (bandaged_time==t){
                health += y;
                bandaged_time=0;
            }            
        }
        health = min(max_health, health);
    }
    
    return health;
}