#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define INF 999999

using namespace std;

int main() {
	int n;
	cin >> n;

	priority_queue<int> q;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (temp != 0) {
			for (int j = 0; j < temp; j++) {
				int num;
				cin >> num;
				q.push(num);
			}
		}
		else {
			if (!q.empty()) {
				cout << q.top() << endl;
				q.pop();
			}
			else {
				cout << -1 << endl;
			}
		}
	}

}