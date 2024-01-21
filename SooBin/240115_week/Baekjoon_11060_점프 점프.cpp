
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>
#include<stack>

#define MAX 9999999

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    vector<int> dp(N, MAX);


    dp[0] = 0;
    for (int i = 0; i < N - 1; i++)
    {
        int num = arr[i];
        for (int j = 1; j <= num; j++)
        {
            if (i + j < N)
            {
                dp[i + j] = min(dp[i + j], dp[i] + 1);
            }

        }
    }

    if (dp[N - 1] == MAX)
    {
        cout << -1;
    }
    else
    {
        cout << dp[N - 1];
    }
  
    return 0;
}
