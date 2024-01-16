#include <iostream>
using namespace std;

int main() {
    int paid;
    cin >> paid;

    // 계산할 거스름돈
    int change = 1000 - paid;

    // 각 동전의 가치
    int coins[6] = {500, 100, 50, 10, 5, 1};

    int count = 0;

    for (int i = 0; i < 6; i++) {
        count += change / coins[i]; // 해당 동전을 최대한 사용
        change %= coins[i]; // 남은 거스름돈
    }

    cout << count << endl;

    return 0;
}
