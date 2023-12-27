#include <bits/stdc++.h>
using namespace std;
int n, k, w, v;
vector<pair<int, int>> product;
int dp[100004];
int main(){
    cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
    // 1. 입력받기
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> w >> v;
        product.push_back({w, v}); // 무게, 가치
    }
    
    // 3. dp 수행
    for(int i=0;i<n;i++){
        tie(w,v) = product[i];
        for(int j=k;j>=w;j--){
            dp[j] = max(dp[j], dp[j-w]+v);
        }
    }
    // 4. 정답 출력
    cout << dp[k];
}

