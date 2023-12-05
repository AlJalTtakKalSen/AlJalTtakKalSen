#include <bits/stdc++.h>
using namespace std;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int solution(string dirs) {
    int answer = 0;
    pair<int, int> current_position = {5, 5};
    map<pair<pair<int, int>, pair<int, int>>, bool> map;
    
    for(char direction: dirs) {
        int y, x;
        tie(y, x) = current_position;
        int ny, nx;
        if(direction == 'U') {
            ny = y + dy[0]; nx = x + dx[0];
        };
        if(direction == 'R') {
            ny = y + dy[1]; nx = x + dx[1];
        };
        if(direction == 'D') {
            ny = y + dy[2]; nx = x + dx[2];
        };
        if(direction == 'L') {
            ny = y + dy[3]; nx = x + dx[3];
        };
        
        if(ny > 10 || nx > 10 || ny < 0 || nx < 0) continue;
        current_position = {ny, nx};
        if(map[{{y, x}, {ny, nx}}] == true) continue;
        
        // 반대로 돌아가는 경우도 포함시켜줘야 함.
        map[{{y, x}, {ny, nx}}] = true;
        map[{{ny, nx}, {y, x}}] = true;
        answer++;
    };
    
    return answer;
}
