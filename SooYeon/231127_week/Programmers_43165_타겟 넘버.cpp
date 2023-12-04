#include <bits/stdc++.h>
using namespace std;
int meet_value, cnt = 0;

void dfs(int value, int sum, int next, vector<int> numbers) {
    sum += value;
    if(next == numbers.size()) {
        if(sum == meet_value) cnt++;
        
        return;
    };
    
    dfs(numbers[next], sum, next+1, numbers);
    dfs(-numbers[next], sum, next+1, numbers);
}

int solution(vector<int> numbers, int target) {
    meet_value = target;
    
    dfs(numbers[0], 0, 1, numbers);
    dfs(-numbers[0], 0, 1, numbers);
    
    return cnt;
}
