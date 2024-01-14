#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    deque<int> dq;
    for (int i = 1; i <= N; ++i) {
        dq.push_back(i);
    }

    int moves = 0;
    while (M--) {
        int target;
        cin >> target;
        
        int index = 0;
        // target의 위치 찾기
        for (int i = 0; i < dq.size(); i++) {
            if (dq[i] == target) {
                index = i;
                break;
            }
        }

        // 왼쪽 이동과 오른쪽 이동 중 더 효율적인 것 선택
        int left = index;
        int right = dq.size() - index;

        moves += min(left, right);

        // 실제로 원소들을 이동시키지 않고, 목표 위치까지 회전
        if (left <= right) {
            while (left--) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } else {
            while (right--) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }

        // 첫 번째 원소 제거
        dq.pop_front();
    }

    cout << moves << endl;

    return 0;
}
