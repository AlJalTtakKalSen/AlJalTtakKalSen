#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

int main() {
    
    int boxSize[1001];
    int dp[1001] = { 0 };

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> boxSize[i];
    }

    int maxSize = 0;
    for (int i = 1; i <= N; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (boxSize[j] < boxSize[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxSize = max(maxSize, dp[i]);
    }
    
    cout << maxSize;
}
