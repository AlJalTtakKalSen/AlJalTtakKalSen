#include <bits/stdc++.h>
using namespace std;

long long gcd(int a, int b) {
    if(a % b == 0) return b;
    else return gcd(b, a % b);
}

long long solution(int w,int h) {
    long long answer = 1;
    
    answer = (long long)w * h;
    
    long long gcd_value = gcd(w, h);
    
    long long remove_w = w / gcd_value;
    long long remove_h = h / gcd_value;
    
    answer -= (remove_w + remove_h - 1) * gcd_value;
    
    return answer;
}
