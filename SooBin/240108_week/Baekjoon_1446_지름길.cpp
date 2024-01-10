#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>

#define MAX 9999999

using namespace std;

int main() 
{
    int N, D;
    cin >> N >> D;
    vector<int> minDist(D + 1, MAX);
    vector<pair<int, int>> array[10001];
    int a, b, dist;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b >> dist;
        array[b].push_back({ a,dist });
        // array[a]에 {b, dist}넣는거 아님!!
    }
    
    minDist[0] = 0;

    for (int i = 1; i <= D; i++)
    {
        if (array[i].size() == 0)
        {
            // 지름길 없음. 
            minDist[i] = minDist[i - 1] + 1;
        }
        else
        {
            for (auto shortcut : array[i])
            {
                minDist[i] = min(
                    minDist[i],
                    min(
                        minDist[i - 1] + 1,
                        // 현재지점 i까지의 최단거리와 해당 지름길을 통해 이동하는 거리를 더한 값
                        minDist[shortcut.first] + shortcut.second
                        )
                    );
            }
        }
    }
    cout << minDist[D];
    return 0;
}
