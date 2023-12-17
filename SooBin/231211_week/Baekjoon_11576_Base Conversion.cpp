#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

int main() {

	int A, B, m;
	cin >> A >> B;
	cin >> m;

	int to_dec = 0;
	while (m--) {
		int num;
		cin >> num;
		to_dec += num * pow(A, m);
	}

	stack<int> ans;
	int div = to_dec;
	while (div) {
		ans.push(div % B);
		div /= B;
	}

	while (!ans.empty()) {
		cout << ans.top() << " ";
		ans.pop();
	}

	return 0;
}