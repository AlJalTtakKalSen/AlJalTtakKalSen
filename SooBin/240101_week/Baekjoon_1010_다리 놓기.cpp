#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

int main() 
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        int answer = 1;
        int N, M;
        cin >> N >> M;

        int temp = 1;
        for (int i = M; i > M - N; i--) {
            answer *= i;
            answer /= temp;
            temp++;
        }
        cout << answer << endl;
    }

    return 0;
}
