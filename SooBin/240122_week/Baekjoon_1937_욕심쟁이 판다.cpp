
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>
#include<stack>

#define MAX 9999999

using namespace std;


int arr[500][500];
int dp[500][500];

int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };

int answer = 0;

int N;

int dfs(int y, int x)
{
    if (dp[y][x])
    {
        return dp[y][x];
    } 
    else
    {
        dp[y][x] = 1;
        for (int a = 0; a < 4; a++)
        {
            int ny = y + dy[a];
            int nx = x + dx[a];
            if (ny >= 0 && ny < N && nx >= 0 && nx < N)
            {
                if (arr[ny][nx] > arr[y][x])
                {
                    dp[y][x] = max(dp[y][x], dfs(ny,nx) + 1);
                }
            }
        }
    }
    return dp[y][x];

}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }

    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            answer = max(answer, dfs(i, j));
        }
    }

    cout << answer;


    return 0;
}
