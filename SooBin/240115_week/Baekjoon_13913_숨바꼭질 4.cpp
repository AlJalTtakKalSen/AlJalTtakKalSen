
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
    int N, K;
    cin >> N >> K;

    vector<bool> visited(100001, false);
    vector<int> previousVisit(100001, -1);

    queue<int> q;
    visited[N] = true;
    q.push(N);

    while (!q.empty())
    {
        int location = q.front();
        q.pop();

        int cases[3] = { location * 2, location + 1, location - 1 };

        for (int i = 0; i < 3; ++i)
        {
            int nextLocation = cases[i];

            if (nextLocation >= 0 && nextLocation < 100001 && !visited[nextLocation])
            {
                visited[nextLocation] = true;
                previousVisit[nextLocation] = location;
                q.push(nextLocation);

                if (nextLocation == K)
                {
                    break;
                }

            }
        }
    }

    stack<int> path;
    int now = K;
    while (now != -1)
    {
        path.push(now);
        now = previousVisit[now];
    }

    cout << path.size() - 1 << endl; 

    while (!path.empty())
    {
        cout << path.top() << " ";
        path.pop();
    }

    return 0;
}
