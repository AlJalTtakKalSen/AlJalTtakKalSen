#include <bits/stdc++.h>

using namespace std;
int n, maxValue, idx;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // 1.입력 받기
    cin >> n;
    vector<int> v(n, 0), dp(n, 1), prev_list(n, -1);
    for (int i=0;i<n;i++){
        cin >> v[i];
    } 
    //2. 가장 긴 증가하는 부분수열 구하기
    for(int j=1;j<n;j++){
        for(int i=0;i<j;i++){
            if((v[i]<v[j]) && (dp[j]<dp[i]+1)){
                dp[j] = dp[i]+1;
                if(maxValue<dp[i]+1){
                    maxValue = dp[i]+1;
                    idx=j;
                }
                prev_list[j]=i;
            }
        }
    }
    // 3. 부분 수열 길이 출력하기
    cout << dp[idx] << "\n";
    // 4. 부분 수열 출력하기
    vector<int> answer;
    for(int i=idx;i!=-1;i = prev_list[i]){
        answer.push_back(v[i]);
    }
    reverse(answer.begin(), answer.end());
    for(int a:answer) cout << a << " ";
}