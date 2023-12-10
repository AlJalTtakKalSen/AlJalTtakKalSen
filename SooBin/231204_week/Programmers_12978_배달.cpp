#include <iostream>
#include <vector>

#define INF 1e9

using namespace std;

int graph[51][51];  // 마을의 개수는 1이상 50이하의 자연수

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    // 최단 거리 테이블을 모두 무한으로 초기화
    for(int i = 0; i < 51; i++){
        fill(graph[i],graph[i]+51,INF);
    }
    
    // 자기 자신에서 자기 자신으로 가는 비용은 0으로 초기화
    for(int a = 1; a <= N; a++){
        for(int b = 1; b <= N; b++){
            if(a == b) graph[a][b] = 0;
        }
    }
    
    for(int i = 0; i < road.size();i++){
        // 양방향 도로.
        // 한 도로의 정보가 중복해서 주어질 수 있으므로 입력값 중 최소값으로 갱신한다.
        graph[road[i][0]][road[i][1]] = min(road[i][2],graph[road[i][0]][road[i][1]]);
        graph[road[i][1]][road[i][0]] = min(road[i][2],graph[road[i][0]][road[i][1]]);
    }
    
    
    // 플로이드 워셜 알고리즘 수행
    for(int k = 1; k <= N; k++) {
        for(int a = 1; a <= N; a++){
            for(int b = 1; b <= N; b++){
                graph[a][b] = min(graph[a][b],graph[a][k] + graph[k][b]);
            }
        }
    }
    
    for(int i = 1; i <= N; i++){
        if(graph[1][i] <= K){
            answer++;
        }
    }
     

    cout << answer << endl;

    return answer;
}