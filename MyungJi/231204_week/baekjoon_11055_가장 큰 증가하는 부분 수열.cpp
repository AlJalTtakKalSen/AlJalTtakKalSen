#include <bits/stdc++.h>

using namespace std;
int n, tmp, answer;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // 1.입력 받기
    cin >> n;
    vector<int> v(n, 0);
    vector<int> dp(n, 0);
    for (int i=0;i<n;i++){
        cin >> tmp;
        v[i] = tmp;
    } 
    // 2. 가장 큰 원소를 기준으로 합 구하기 
    dp[0] = v[0];
    for(int i=1;i<n;i++){
            int tmpSum=0;
            for (int k=i-1;k>=0;k--){
                if(v[k]<v[i]) {
                    tmpSum = max(tmpSum, dp[k]);
                }
            if (tmpSum==0) dp[i]=v[i];
            else dp[i] = tmpSum + v[i]; 
        }
    }
    //3. 가장 큰 합 구하기
    answer=dp[0];
    for(int i=0;i<n;i++){
        answer = max(dp[i], answer);
    }
    //4. 정답 출력
    cout << answer;
}