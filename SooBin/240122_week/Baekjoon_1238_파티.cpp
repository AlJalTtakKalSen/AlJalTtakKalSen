
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

int N, M, X;
vector<pair<int, int>> graph[1001];
int d[1001];
int rd[1001];

void dijkstra(int start)
{
    for (int i = 1; i <= N; i++)
    {
        d[i] = MAX;
    }
    priority_queue<pair<int, int>> q;
    d[start] = 0;
    q.push(make_pair(0,start));
    while (!q.empty())
    {
        int cost = -q.top().first;
        int now = q.top().second;
        q.pop();
        if (d[now] < cost) continue;
        for (int i = 0; i < graph[now].size(); i++)
        {
            int newCost = cost + graph[now][i].second;
            if (newCost < d[graph[now][i].first])
            {
                d[graph[now][i].first] = newCost;
                q.push(make_pair(-newCost, graph[now][i].first));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> X;
    for (int i = 0; i < M; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back(make_pair(to,cost));
    }

    for (int i = 1; i <= N; i++)
    {
        dijkstra(i);
        rd[i] = d[X];
    }

    fill(d, d + 1001, MAX);
    dijkstra(X);

    int answer = 0;
    for (int i = 1; i <= N; i++)
    {
        answer = max(answer,d[i] + rd[i]);
    }
    cout << answer;
    return 0;
}
