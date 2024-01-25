#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<cmath>

#define MAX 9999999

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int numCount[10] = { 0 };

    string s = to_string(N);
    for (char c : s)
    {
        int index = c - '0';
        numCount[index]++;
    }

    numCount[6] = ceil((numCount[6] + numCount[9]) / 2.0);
    int maxCount = 0;
    for (int i = 0; i < 9; i++)
    {
        maxCount = max(maxCount,numCount[i]);
    }
    cout << maxCount;

    return 0;
}
