
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>
#include<stack>
#include<string>
#include<sstream>

#define MAX 9999999

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    bool arr[100][100] = { false };
    int N;
    cin >> N;
    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        int startX, startY;
        cin >> startX >> startY;
        for (int a = 0; a < 10; a++)
        {
            for (int b = 0; b < 10; b++)
            {
                if (!arr[startX + a][startY + b])
                {
                    answer++;
                    arr[startX + a][startY + b] = true;
                }

            }
        }
    }
    cout << answer;
    return 0;
}
