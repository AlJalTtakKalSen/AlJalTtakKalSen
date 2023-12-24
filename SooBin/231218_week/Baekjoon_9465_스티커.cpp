#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define INF 999999

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		
		int n;
		cin >> n;

		// 2차원 벡터 선언과 0으로 초기화
		vector<vector<int>> array(2, vector<int>(n,0));
		vector<vector<int>> dp(2, vector<int>(n,0));
		
		int temp = 0;
		for (int a = 0; a < 2; a++) {
			for (int b = 0; b < n; b++) {
				cin >> temp;
				array[a][b] = temp;
			}
		}

		dp[0][0] = array[0][0];
		dp[1][0] = array[1][0];

		for (int i = 1; i < n; i++) {
			if (i == 1) {
				dp[0][1] = array[1][0] + array[0][1];
				dp[1][1] = array[0][0] + array[1][1];
			}
			else {
				dp[0][i] = max(dp[1][i - 1] + array[0][i], dp[1][i - 2] + array[0][i]);
				dp[1][i] = max(dp[0][i - 1] + array[1][i], dp[0][i - 2] + array[1][i]);
			}

		}

		cout << max(dp[0][n - 1], dp[1][n - 1]) << endl;

	}

}