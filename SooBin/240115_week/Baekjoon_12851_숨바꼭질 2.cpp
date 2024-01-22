
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>

#define MAX 9999999

using namespace std;

int main() 
{
    int N, K;
    cin >> N >> K;
    bool visited[100001] = { false };

    queue<pair<int, int>> q;
    visited[N] = true;
    q.push(make_pair(N,0));

    while (!q.empty())
    {
        int location = q.front().first;
        int time = q.front().second;
        q.pop();
        visited[location] = true;

        if(location == K)
        {
            cout << time;
            break;
        }

        int case1 = location * 2;
        int case2 = location + 1;
        int case3 = location - 1;

        if (case1 >= 0 && case1 <= 100001 && !visited[case1])
        {
            q.push(make_pair(case1, time));
        }
        if (case2 >= 0 && case2 <= 100001 && !visited[case2])
        {
            q.push(make_pair(case2, time + 1));
        }
        if (case3 >= 0 && case3 <= 100001 && !visited[case3])
        {
            q.push(make_pair(case3, time + 1));
        }

    }

    return 0;
}
