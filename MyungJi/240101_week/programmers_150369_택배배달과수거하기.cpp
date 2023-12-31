// 내 코드 아님
#include <bits/stdc++.h>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;

    int del = 0;
    int pic = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (deliveries[i] != 0 || pickups[i] != 0)
        {
            int cnt = 0;
            while (del < deliveries[i] || pic < pickups[i])
            {
                ++cnt;
                del += cap;
                pic += cap;
            }
            del -= deliveries[i];
            pic -= pickups[i];
            answer += (1LL * cnt) * (1LL * (i + 1)) * 2;
        }
    }

    return answer;
}
