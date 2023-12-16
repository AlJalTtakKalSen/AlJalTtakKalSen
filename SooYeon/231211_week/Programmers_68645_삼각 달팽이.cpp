#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int arr[1001][1001];
    
    int cnt = n;
    int col_idx = 0, row_idx = 0;
    int num = 1;
    
    while(cnt > 0) {
        // 아래로 내려가기
        int temp_row_idx = row_idx;
        int temp_col_idx = col_idx;
        
        for(int i = row_idx; i < row_idx + cnt; i++) {
            arr[i][col_idx] = num++;
            temp_row_idx++;
        }

        temp_row_idx -= 1;
        row_idx = temp_row_idx;
        temp_col_idx += 1;
        col_idx = temp_col_idx;
        cnt--;
        
        // 옆으로 가기
        for(int i = col_idx; i < col_idx + cnt; i++) {
            arr[row_idx][i] = num++;
            temp_col_idx++;
        }
        
        temp_col_idx -= 2;
        temp_row_idx -= 1;
        col_idx = temp_col_idx;
        row_idx = temp_row_idx;
        cnt--;
        
        // 대각선 올라가기
        for(int i = cnt; i > 0; i--) {
            arr[temp_row_idx--][temp_col_idx--] = num++;
        }
        cnt--;
        col_idx = temp_col_idx + 1;
        row_idx = temp_row_idx + 2;
    
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i+1; j++) {
            answer.push_back(arr[i][j]);
        };
    };
    
    return answer;
}
