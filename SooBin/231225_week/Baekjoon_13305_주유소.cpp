#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define INF 999999

using namespace std;


int main() {
    int N;
    cin >> N;

    vector<int> l;
    vector<int> c;

    int temp;
    for (int i = 0; i < N - 1; i++) {
        cin >> temp;
        l.push_back(temp);
    }
    for (int i = 0; i < N; i++) {
        cin >> temp;
        c.push_back(temp);
    }

    long long minCost = c[0];
    long long answer = minCost * l[0];

    for (int i = 1; i < N-1 ; i++) {
        if (c[i] > minCost) {
            answer += minCost * l[i];
        }
        else {
            minCost = c[i];
            answer += minCost * l[i];
        }
    }

    cout << answer;

    return 0;
}