#include <bits/stdc++.h>
using namespace std;
int n, k, bag[300001];
long long result = 0;
vector<pair<int, int>> v;
priority_queue<int> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	int first, second;
	for (int i = 0; i < n; i++) {
		cin >> first >> second;
		v.push_back({ first, second });
	};
	for (int i = 0; i < k; i++) {
		cin >> bag[i];
	};

	// 보석, 가방을 오름차순 정렬
	sort(v.begin(), v.end());
	sort(bag, bag + k);

	int idx = 0;
	// 가장 가벼운 가방부터 들어갈 수 있는 보석 중 가장 비싼 보석을 넣는다.
	for (int i = 0; i < k; i++) {
		// 가방보다 큰 보석일 경우 while break;
		while (idx < n && v[idx].first <= bag[i]) {
			pq.push(v[idx].second);
			idx++;
		};

		if (!pq.empty()) {
			// 가방에 담은 보석 중 가장 비싼 보석을 더함
			result += pq.top();
			pq.pop();
		};
	};

	cout << result << "\n";

	return 0;
}
