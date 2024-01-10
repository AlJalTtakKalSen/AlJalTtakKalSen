#include <bits/stdc++.h>
using namespace std;
int tri[504][504];
int n, answer;

int main(){
    //1. 입력받기
    cin >> n;
    for (int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin >> tri[i][j];
        }
    }
    //2. 합 구하기
    for (int i=n-2;i>=0;i--){
        for (int j=0;j<=i;j++){ 
            tri[i][j] = tri[i][j] + max(tri[i+1][j], tri[i+1][j+1]);
        }
    }
    //3. 정답 출력하기
    cout << tri[0][0];
}

