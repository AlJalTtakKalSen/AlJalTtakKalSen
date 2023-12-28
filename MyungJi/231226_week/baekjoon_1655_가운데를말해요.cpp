#include <bits/stdc++.h>
using namespace std;
int n, num;
priority_queue<int, vector<int>, greater<int>> minHeap; //오름차순 큐
priority_queue<int> maxHeap; // 내림차순 큐 

int main(){
    cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
    // 1. 입력받기
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> num;
        //2. 큐에 원소 삽입하기
        if (maxHeap.empty() || maxHeap.top()>=num){
            maxHeap.push(num);
        }
        else minHeap.push(num);
        //3. 큐 조정작업 수행
        if (maxHeap.size()<minHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        else if (maxHeap.size()>minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        //4. 정답 출력
        cout << maxHeap.top() << "\n";
    }
    
}

