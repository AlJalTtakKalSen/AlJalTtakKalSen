
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
    int M, N;
    cin >> M >> N;

    vector<int> v;

    int left = 1;
    int right = 0;

    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
        right = max(right, temp);
    }

    int answer = 0;

    while (left <= right)
    {
        int count = 0;
        int mid = (left + right) / 2;
        for (int i = 0; i < N; i++)
        {
            count += v[i] / mid;
        }
        if (count < M)
        {
            right = mid - 1;
        } 
        else
        {
            left = mid + 1;
            answer = mid;
        }

    }

    cout << answer;
    return 0;
}
 