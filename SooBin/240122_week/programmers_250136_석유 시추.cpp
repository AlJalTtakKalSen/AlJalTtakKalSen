#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int arr[500][500];
bool visited[500][500] = {false};

int dy[4] = {0,0,-1,1};
int dx[4] = {1,-1,0,0};

int n,m;

queue<pair<int,int>> q;
queue<pair<int,int>> q2;
set<int> xs;
int xCount[500] = {0};

vector<int> x(n);

void bfs()
{   
    int count = 1;
    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        xs.insert(x);
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m ) continue;
            if(arr[ny][nx] == 1 && !visited[ny][nx])
            {
                visited[ny][nx] = true;
                count++;
                q.push(make_pair(ny,nx));
                q2.push(make_pair(ny,nx));
            }
        }
    }
    while(!q2.empty())
    {
        int y = q2.front().first;
        int x = q2.front().second;
        q2.pop();
        arr[y][x] = count;
    }
    
    for(auto x : xs){
        xCount[x] += count;
    }
    xs.clear();
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    
    n = land.size();
    m = land[0].size();
    
    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < m; x++)
        {
            arr[y][x] = land[y][x];
        }
    }
    
    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < m; x++)
        {
            if(arr[y][x] == 1 && !visited[y][x])
            {
                q.push(make_pair(y,x));
                q2.push(make_pair(y,x));
                visited[y][x] = true;
                bfs();
            }
        }
    }     

    for(int i = 0; i < m; i++ )
    {
        answer = max(answer,xCount[i]);
    }
        
    return answer;
}