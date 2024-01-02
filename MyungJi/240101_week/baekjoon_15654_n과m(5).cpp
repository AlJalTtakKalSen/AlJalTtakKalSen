#include <bits/stdc++.h>
using namespace std;
int n, m, tmp;
int visited[10], num[10];
vector<int> arr;
void dfs(int here, int cnt){
    if (cnt==m){
        for(int i=0;i<m;i++) cout << arr[num[i]] << " ";
        cout << "\n";
        return;
    }
    for (int i=0;i<n;i++){
        if (!visited[i]){
            visited[i] = 1; 
            num[cnt] = i;
            dfs(i, cnt+1);
            visited[i]=0;
        }
    }
    
}


int main(){
    //1. 입력받기
    cin >> n >> m;
    for (int i=0;i<n;i++){
        cin >> tmp;
        arr.push_back(tmp);
    } 
    sort(arr.begin(), arr.end());
    //2. dfs 수행
    dfs(0, 0);
}