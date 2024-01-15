
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

    // 우선순위 큐
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    visited[N] = true;
    q.push(make_pair(0, N));

    while (!q.empty())
    {
        int time = q.top().first;
        int location = q.top().second;
        q.pop();

        if (location == K)
        {
            cout << time;
            break;
        }

        int case1 = location * 2;
        int case2 = location + 1;
        int case3 = location - 1;

        if (case1 >= 0 && case1 <= 100001 && !visited[case1])
        {
            visited[case1] = true;
            q.push(make_pair(time, case1));
        }
        if (case2 >= 0 && case2 <= 100001 && !visited[case2])
        {
            visited[case2] = true;
            q.push(make_pair(time + 1, case2));
        }
        if (case3 >= 0 && case3 <= 100001 && !visited[case3])
        {
            visited[case3] = true;
            q.push(make_pair(time + 1, case3));
        }

    }

    return 0;
}