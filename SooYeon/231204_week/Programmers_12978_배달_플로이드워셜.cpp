#include <bits/stdc++.h>
using namespace std;
int graph[51][51];

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    for(int i = 0; i < 51; i++) {
        fill(graph[i], graph[i] + 51, 987654321);
    }
    
    for(int i = 0; i < road.size(); i++) {
        // 마을 a와 b 사이의 경로가 2개 이상일 수 있으니, 입력받을 때마다 최소값으로 갱신
        graph[road[i][0]][road[i][1]] = min(graph[road[i][0]][road[i][1]], road[i][2]);
        graph[road[i][1]][road[i][0]] = min(graph[road[i][0]][road[i][1]], road[i][2]);
    };
    
    for(int k=1; k<=N; k++) {
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=N; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    
    for(int i = 1; i <= N; i++) graph[i][i] = 0;
    for(int i = 1; i <= N; i++) {
        if(graph[1][i] <= K) answer++;
    }
    
    return answer;
}
