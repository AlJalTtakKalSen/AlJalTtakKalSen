#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

int main() {
    int N;
    int arr[301];
    int dp[301];
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    dp[0] = arr[0];
    dp[1] = max(arr[1], arr[0] + arr[1]);
    dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);

    for (int i = 3; i < N; i++) {
        dp[i] = max(arr[i] + dp[i - 2], arr[i] + arr[i - 1] + dp[i - 3]);
    }

    cout << dp[N-1];
}
