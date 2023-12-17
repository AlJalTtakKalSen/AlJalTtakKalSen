#include <bits/stdc++.h>
using namespace std;
int one = 0, zero = 0;

// 매개변수로 전달해주는 동시에 새로 할당하지 않도록 해야 한다.
// 그렇지 않으면 매번 새로 vector 배열을 할당해주는데 메모리 및 시간을 사용하여 시간초과가 난다.
void quad(int y, int x, int size, const vector<vector<int>>& arr) {
    bool quad_one = false, quad_zero = false;
    
    // 전달받은 정사각형 안의 값들 확인
    for(int i = y; i < y + size; i++) {
        for(int j = x; j < x + size; j++) {
            if(arr[i][j] == 0) quad_zero = true;
            else quad_one = true;
        };
    };
    
    if(quad_zero && quad_one) {
        // 1과 0이 섞여있는 경우, 다시 재귀함수 호출
        int quad_size = size / 2;
        quad(y, x + quad_size, quad_size, arr); // 1사분면
        quad(y, x, quad_size, arr); // 2사분면
        quad(y + quad_size, x, quad_size, arr); // 3사분면
        quad(y + quad_size, x + quad_size, quad_size, arr); // 4사분면
    }
    else if(quad_zero) {
        // 0만 있는 경우
        zero++;
        return;
    }
    else {
        // 1만 있는 경우
        one++;
        return;
    }
    return;
}

// 재귀 탐색
vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    int col_row = arr.size() / 2; // 처음으로 나누는 정사각형 한 변의 길이
    
    // 재귀 함수 실행
    // 정사각형을 4분위로 나누는 행동을 재귀적으로 실행
    // 시작 x, y, 사각형 한 변의 길이 전달
    quad(col_row, 0, col_row, arr); // 1사분면
    quad(0, 0, col_row, arr); // 2사분면
    quad(0, col_row, col_row, arr); // 3사분면
    quad(col_row, col_row, col_row, arr); // 4사분면
    
    // 0만 4개 혹은 1만 4개인 경우는 전체 정사각형이 하나의 수로 이루어진 경우
    if(zero == 4 && one == 0) {
        answer.push_back(1);
        answer.push_back(0);
    }
    else if(one == 4 && zero == 0) {
        answer.push_back(0);
        answer.push_back(1);
    }
    else {
        answer.push_back(zero);
        answer.push_back(one);
    }
        
    return answer;
}
