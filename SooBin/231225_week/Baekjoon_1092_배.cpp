#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

int main() {
    int temp;

    int N;
    vector<int> crane;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        crane.push_back(temp);
    }

    int M;
    vector<int> box;
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        box.push_back(temp);
    }

    sort(crane.begin(),crane.end());
    sort(box.begin(), box.end());

    if (crane.back() < box.back()) {
        cout << -1;
        return 0;
    }

    int answer = 0;
    while (!box.empty()) {
        answer++;
        for (int i = 0; i < crane.size(); i++) {
            for (int j = 0; j < box.size(); j++) {
                if (crane[crane.size() - 1 - i] >= box[box.size() - 1 - j]) {
                    box.erase(box.begin() + box.size() - 1 - j);
                    break;
                }
            }
        }
    }

    cout << answer;
}

  