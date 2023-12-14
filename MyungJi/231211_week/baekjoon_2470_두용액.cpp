#include <bits/stdc++.h>

using namespace std;
int n, minSum=2000000000;

int main(void) {
    //1. 입력받기
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    //2. 이진 탐색 수행
    int l=0, r=n-1;
    pair<int, int> answer={l, r};
    while(l<r){
        int currentSum = v[l]+v[r];
        if(minSum>abs(currentSum)){
            minSum = abs(currentSum);
            answer = {l,r};
            if(currentSum==0) break;
        }
        if(currentSum<0) l++;
        else r--;
    }
    cout << v[answer.first] << " "<< v[answer.second];

    return 0;
}