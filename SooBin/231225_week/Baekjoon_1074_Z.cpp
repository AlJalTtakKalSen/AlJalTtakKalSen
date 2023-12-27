#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define INF 999999

using namespace std;

long long fibo[50] = {0};

long long f(int num) {
    if (num == 0 || num == 1) {
        return fibo[num];
    }
    else if (fibo[num] == 0) {
        fibo[num] = f(num - 1) + f(num - 2);
    }
    return fibo[num];
}

int main() {
   
    fibo[0] = 0;
    fibo[1] = 1;
    int num;

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> num;
        if (num == 0) {
            cout << "1 0" << endl;
        }
        else {
            cout << f(num - 1) << " " << f(num) << endl;
        }

    }

    return 0;
}