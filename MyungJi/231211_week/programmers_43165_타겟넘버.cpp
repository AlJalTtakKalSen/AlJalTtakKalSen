#include <bits/stdc++.h>

using namespace std;

int makeTarget(vector<int> &numbers, int target, int totalSum, int pos){
    if (pos==numbers.size()) {
        return target==totalSum? 1 : 0;
    }
    return makeTarget(numbers, target, totalSum+numbers[pos], pos+1)+ makeTarget(numbers, target, totalSum-numbers[pos], pos+1);
}

int solution(vector<int> numbers, int target) {
    
    return makeTarget(numbers, target, 0, 0);
}