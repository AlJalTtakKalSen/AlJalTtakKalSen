#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>

#define MAX 9999999

using namespace std;

int main() 
{
    unsigned  answer = 0;
    int K, N;
    cin >> K >> N;

    vector<int> v;
    unsigned  temp;
    unsigned int maxLength = 0;
    for (int i = 0; i < K; i++)
    {
        cin >> temp;
        v.push_back(temp);
        maxLength = max(maxLength, temp);
    }
    unsigned int start = 1;
    unsigned int mid;
    unsigned int end = maxLength;


    while (start <= end)
    {
        mid = (start + end) / 2;

        unsigned int sum = 0;
        for (int i = 0; i < K; i++)
        {
            sum += v[i] / mid;
        }
        if (sum >= N)
        {
            start = mid + 1;
            answer = max(answer, mid);
        } 
        else
        {
            end = mid - 1;
        }

    }

    cout << answer;
    return 0;
}
