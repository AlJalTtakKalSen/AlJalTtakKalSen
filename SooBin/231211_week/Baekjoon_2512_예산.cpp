#include <iostream>
#include <vector>
#include <queue>
#include <stack>


using namespace std;

int main() {
    
    int N;
    cin >> N;

    vector<int> arr;
    int max_budget = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
        max_budget = max(max_budget, x);
    }

    int target;
    cin >> target;
    
    int start = 0;
    int end = max_budget;

    int result = 0;
    while (start <= end) {
        long long int total = 0;
        int mid = (start + end) / 2;
        for (int i = 0; i < N; i++) {
            if (arr[i] < mid) {
                total += arr[i];
            }
            else {
                total += mid;
            }
        }
        if (total > target) {
            end = mid - 1;
        }
        else {
            result = mid;
            start = mid + 1;
        }
        
    }
 
    cout << result << '\n';

    return 0;
}