#include <bits/stdc++.h>

using namespace std;
int dh[]={-1,0,1,0};
int dw[]={0,1,0,-1};
int cnt;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;    
    for (int i=0;i<4;i++){
        int nh = h+ dh[i];
        int nw = w+dw[i];
        if (nh<0||nw<0||nh>=board.size()||nw>=board[0].size()) continue;
        if (board[nh][nw] == board[h][w]) cnt++;
    }
    return cnt;
}