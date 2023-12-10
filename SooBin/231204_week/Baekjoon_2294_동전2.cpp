#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);   // 화폐 가치 저장
    vector<int> d(k + 1, 99999);   // dp수행, 99999로 초기화

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    d[0] = 0;   // 0원을 만들 수 있는 경우의 수는 0으로 초기화

    for (int i = 0; i < n; i++) { // 각 화폐단위마다 반복문 수행
        d[v[i]] = 1;
        for (int j = v[i]; j <= k; j++) {
            if (d[j - v[i]] != 99999) {
                d[j] = min(d[j], d[j - v[i]] + 1);
            }
        }
    }

    if (d[k] == 99999) {
        cout << -1;
    }
    else {
        cout << d[k];
    }

    return 0;
}