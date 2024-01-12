#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health;
    int skillTime = bandage[0];
    int heal = bandage[1];
    int additionalHeal = bandage[2];
    
    int lastAttackTime = attacks.back()[0];
    int index = 0;
    int continuousHeal = 0;
    
    for(int i = 0; i <= lastAttackTime; i++)
    {
        if(i == attacks[index][0])
        {
            answer -= attacks[index][1];
            if(answer <= 0)
            {
                return -1;
            }
            continuousHeal = 0;
            index++;
        } 
        else
        {
            answer += heal;
            continuousHeal++;
            if(continuousHeal == skillTime)
            {
                answer += additionalHeal;
                continuousHeal = 0;
            }
            if(answer > health)
            {
                answer = health;
            }
        }
        // cout << i << " : " << answer << endl;
    }
    return answer;
}