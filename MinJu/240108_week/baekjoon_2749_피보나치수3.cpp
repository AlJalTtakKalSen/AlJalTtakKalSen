#include <bits/stdc++.h>
using namespace std;

int main() {
    const int MOD = 1000000;
    const int PISANO_PERIOD = 1500000;
    long long n;
    // 1. 입력받기
    cin >> n;
    //2. PISANO PERIOD 만큼 fib 채우기
    int fib[PISANO_PERIOD] = {0, 1};
    
    for (int i = 2; i < PISANO_PERIOD; ++i) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }
    //3. 정답 출력
    cout << fib[n % PISANO_PERIOD] << endl;

    return 0;
}
