#include <bits/stdc++.h>
int maxY, minY;
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    // 1. r1, r2 원 안의 점 구하기
    for (int r=1;r<r2;r++){
        maxY = floor(sqrt(pow(r2,2) - pow(r, 2)));
        minY = ceil(sqrt(pow(r1,2) - pow(r, 2)));
        if (r<r1){
            answer += (maxY-minY)+1;
        }
        else answer += maxY;
    }
    // 2. y축 점 구하기
    answer += (r2 - r1) + 1;
    // 3. 4분면 고려
    answer *= 4;
    return answer;
}