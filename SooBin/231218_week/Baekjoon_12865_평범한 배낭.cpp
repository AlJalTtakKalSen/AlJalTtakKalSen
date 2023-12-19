#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> arr(N); 
    vector<int> d(K + 1, 0);       

    for (int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    for (int i = 0; i < N; i++) {
        int weight = arr[i].first;
        int value = arr[i].second;

        for (int j = K; j >= weight; j--) {
            d[j] = max(d[j], d[j - weight] + value);
        }
    }

    cout << d[K] << '\n';

    return 0;
}