#include <bits/stdc++.h>
using namespace std;
int n, m, r, c ,d, ret, ny, nx;
int dy[]={-1, 0, 1, 0};
int dx[]={0, 1, 0, -1};
int mp[54][54], cleaned[54][54];

void cleanRoom(int y, int x, int d){
    if(cleaned[y][x]==0) {
        cleaned[y][x]=1;
        ret++;
    }
    // 주변 4칸 중 청소되지 않은 빈 칸이 있는지 확인
    for (int i=0;i<4;i++){
        int nextD = (d+3)%4; //반시계방향으로 회전
        int ny = y +dy[nextD];
        int nx = x + dx[nextD];
        if(ny>=0 && nx>=0 && ny<n && nx<m && mp[ny][nx]==0 && cleaned[ny][nx]==0) {
            cleanRoom(ny, nx, nextD);
            return;
        }
        d = nextD;

    }
    // 청소되지 않은 빈칸이 없는 경우
        int backD = (d + 2) % 4; // 반시계 회전
        // 후진
        ny = y + dy[backD]; 
        nx = x + dx[backD];
        if(ny>=0 && nx>=0 && ny<n && nx<m && mp[ny][nx]==0){
            cleanRoom(ny, nx, d);
        }
}

int main(){
    //1. 입력받기
    cin >> n >> m;
    cin >> r >> c >> d;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mp[i][j];
        }
    }
    //2. 청소
    cleanRoom(r, c, d);  
    //3. 정답 출력
    cout << ret;  
}