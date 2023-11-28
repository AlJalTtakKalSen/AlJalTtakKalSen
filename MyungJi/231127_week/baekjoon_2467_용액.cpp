#include <bits/stdc++.h>
using namespace std;
int n, tmp;
vector<int> v;
int minDiff=INT_MAX;
pair<int, int> p;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //1. 입력받기
    cin >> n;
    for (int i=0;i<n;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    //2. 오름차순 정렬
    sort(v.begin(), v.end());
    //3. 투포인터
    int i=0, j=n-1;
    int sum=0;
    while((i<n) && (j>=0)){
        if(i>=j) break; // 종료조건
        sum = v[i] + v[j];
        // 절대값 합이 최소일 경우 기록
        if(abs(sum)<=minDiff){
            minDiff = abs(sum);
            p = {i,j};
        }
        // 합이 음수 또는 0일 경우 양수 증가
        if(sum<=0){
            i++;
        // 그렇지 않으면 음수 증가
        } else j--;
    }
    //3. 정답 출력
    cout << v[p.first] << " " << v[p.second];

}