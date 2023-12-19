#include <bits/stdc++.h>

using namespace std;

int l[3][3], xCnt, oCnt;
bool oFlag, xFlag;

bool checkWin(int num){
    for(int i=0;i<3;i++){
        if (l[i][0]== num && l[i][1]==num && l[i][2]==num) return true;
        if (l[0][i]== num && l[1][i]==num && l[2][i]==num) return true;
    }
    if (l[0][0]==num && l[1][1]==num && l[2][2]==num) return true;
    if (l[0][2]==num && l[1][1]==num && l[2][0]==num) return true;
    return false;
}

int solution(vector<string> board) {
    // 1. 배열 생성
    for(int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            char c = board[i][j];
            if (c=='O'){
                l[i][j] = 1;
                oCnt++;
            } 
            else if (c=='X'){
                l[i][j]=2;
                xCnt++;
            } 
            else l[i][j]=0;
        } 
    }
    // 2. 갯수 확인
    int diff = oCnt-xCnt;
    if (diff>=2 || diff<0) return 0;
    // 3. 구현  
    oFlag = checkWin(1);
    xFlag = checkWin(2);
        
    if (oFlag && xFlag) return 0;
    if (oFlag)
        return oCnt==xCnt+1 ? 1 : 0;
    if (xFlag)
        return oCnt==xCnt ? 1 : 0;
    
    return 1;
}