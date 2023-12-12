#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
int graph[204][204];
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    //1. 초기화 + 입력
    fill(&graph[0][0], &graph[0][0]+204*204, INF);
    for(int i=0;i<fares.size();i++){
        graph[fares[i][0]][fares[i][1]] = min(graph[fares[i][0]][fares[i][1]], fares[i][2]);
        graph[fares[i][1]][fares[i][0]] = min(graph[fares[i][1]][fares[i][0]], fares[i][2]);
    }
    for(int i=1;i<=n;i++){
        graph[i][i]=0;
    }
    //2. 플로이드-워셜 알고리즘 수행
    for(int k=1;k<=n;k++){
        for(int a=1;a<=n;a++){
            for(int b=1;b<=n;b++){
                graph[a][b] = min(graph[a][b], graph[a][k]+graph[k][b]);
            }
        }
    }
    //3. 합승할때의 최소 시간 구하기
    int answer = INF;
    for(int i=1;i<=n;i++){
        if (graph[s][i] == INF || graph[i][a]==INF||graph[i][b]==INF) continue;
        answer = min(answer, graph[s][i]+graph[i][a]+graph[i][b]);
    }
    if (graph[s][a]!=INF && graph[s][b]!=INF) answer = min(answer, graph[s][a]+graph[s][b]);

    return answer;
}