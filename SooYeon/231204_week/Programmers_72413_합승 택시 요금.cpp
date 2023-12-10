#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int graph[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    
    for(int i = 0; i < 201; i++) {
        fill(graph[i], graph[i] + 201, INF);
    }
    
    for(int i = 0; i < fares.size(); i++) {
        graph[fares[i][0]][fares[i][1]] = fares[i][2];
        graph[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    
    for(int k = 1; k <= n; k++) {
        for(int a = 1; a <= n; a++) {
            for(int b = 1; b <= n; b++) {
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        graph[i][i] = 0;
    }
    
    for(int i = 1; i <= n; i++) {
        if(graph[i][a] == INF || graph[i][b] == INF) continue;

        cout << graph[s][i] << ":" << graph[i][a] << ":" << graph[i][b] << "\n";
        answer = min(graph[s][i] + graph[i][a] + graph[i][b], answer);
    };
    
    return answer;
}
