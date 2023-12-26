#include <bits/stdc++.h>
using namespace std;

int n, pNum, mNum, muNum, dNum;
int mxSum=-1e9-1, mnSum=1e9+1;
int l[104];

void makeNum(int sum, int pos, int pNum, int mNum, int muNum, int dNum){
    if(pos==n){
        if (mxSum<sum) mxSum = sum;
        if (mnSum>sum) mnSum=sum;
        return;
    }
    if(pNum>0) makeNum(sum+l[pos], pos+1, pNum-1, mNum, muNum, dNum);
    if(mNum>0) makeNum(sum-l[pos], pos+1, pNum, mNum-1, muNum, dNum);
    if(muNum>0) makeNum(sum*l[pos], pos+1, pNum, mNum, muNum-1, dNum);
    if(dNum>0) makeNum(sum/l[pos], pos+1, pNum, mNum, muNum, dNum-1);
}

int main(){
    cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
    // 1. 입력받기
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> l[i];
    }
    cin >> pNum >> mNum >> muNum >> dNum;
    //2. dfs 수행
    makeNum(l[0], 1, pNum, mNum, muNum, dNum);
    //3. 정답 출력
    cout << mxSum << "\n" << mnSum << "\n";
}