#include <bits/stdc++.h>

using namespace std;
int t, w, apple[1004], answer;

int dp[1004][3][34];

int move(int time, int pos, int cnt){ // 시간, 위치, 움직인 횟수
    if (time>t) return 0;
    if (cnt>w) return 0;
    if(dp[time][pos][cnt] != -1)  return dp[time][pos][cnt];
    int nextPos = pos==1 ? 2 : 1;
    dp[time][pos][cnt] = max(move(time+1, pos, cnt), move(time+1, nextPos, cnt+1)) + (apple[time] == pos);
    
    return dp[time][pos][cnt];
}

int main(void) {
    //1. 입력받기
    cin >> t >> w;
    for(int i=0;i<t;i++){
        cin >> apple[i];
    }
    fill(&dp[0][0][0], &dp[0][0][0]+1004*3*34, -1);
    //2. 움직이기
    answer = max(move(0,1,0), move(0,2,1));
    cout << answer;
    return 0;
}