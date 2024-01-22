
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int H, W;
    cin >> H >> W;
    vector<int> v;
    for (int i = 0; i < W; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    int answer = 0;
    
    for (int i = 1; i < W; i++)
    {
        int leftMax = 0;
        for (int left = 0; left < i; left++)
        {
            leftMax = max(leftMax,v[left]);
        }
        int rightMax = 0;
        for (int right = i + 1; right < W; right++)
        {
            rightMax = max(rightMax, v[right]);
        }
      
        int temp = min(leftMax, rightMax) - v[i];
        if (temp > 0)
        {
            answer += temp;
        }
        
    }
    cout << answer;
    return 0;
}
