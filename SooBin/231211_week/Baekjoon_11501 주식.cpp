#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#define INF 999999

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N; 
        cin >> N;

        stack<int> s;
        for (int i = 0; i < N; i++) {
            int temp;
            cin >> temp;
            s.push(temp);
        }
        
        long long answer = 0;
        int max = 0;
        while (!s.empty()) {
            int now = s.top();
            s.pop();
            if (now < max) {
                answer += max - now;
            }
            else if (now > max) {
                max = now;
            }
        }

        cout << answer << '\n';

    }
    
    return 0;
}