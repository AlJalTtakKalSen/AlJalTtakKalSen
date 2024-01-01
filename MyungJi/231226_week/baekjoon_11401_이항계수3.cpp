#include <iostream>
using namespace std;

const int MOD = 1000000007;

// 빠른 거듭제곱 함수
long long pow(long long base, int exponent) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exponent /= 2;
    }
    return result;
}

// 모듈로 역원 계산 함수
long long modInverse(long long a) {
    return pow(a, MOD - 2);
}

// 팩토리얼 계산 함수
long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result = (result * i) % MOD;
    }
    return result;
}

int main() {
    int N, K;
    cin >> N >> K;

    // N!, K!, (N-K)! 계산
    long long factN = factorial(N);
    long long factK = factorial(K);
    long long factNK = factorial(N - K);

    // 결과 계산
    long long result = factN * modInverse(factK) % MOD * modInverse(factNK) % MOD;
    cout << result << endl;

    return 0;
}
