#include <iostream>
#include <vector>
#include <queue>

using namespace std;


// N = 노드의 개수
// M = 간선의 개수
int N, M;

// 모든 노드에 대한 진입 차수는 0으로 초기화
int indegree[32001];

// 각 노드에 연결된 간선 정보를 담기 위한 연결 리스트 초기화
vector<int> graph[32001];

void sort() {
    // 위상정렬 수행 결과를 담을 리스트
    vector<int> result;

    // 큐 라이브러리 사용
    // 오름차순 우선순위 큐
    priority_queue<int,vector<int>,greater<int>> q;

    // 먼저 진입차수가 0인 노드를 큐에 삽입
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // 큐가 빌 때까지 반복
    while (!q.empty()) {
        // 큐에서 원소 꺼내기
        // 우선순위 큐에서는 front가 아닌 top
        int now = q.top();
        q.pop();
        result.push_back(now);
        // 위 원소와 연결된 노드들의 진입차수에서 1 빼기
        for (unsigned int i = 0; i < graph[now].size(); i++) {
            indegree[graph[now][i]] -= 1;
            // 새롭게 진입차수가 0이 되는 노드를 큐에 삽입
            if (indegree[graph[now][i]] == 0) {
                q.push(graph[now][i]);
            }
        }
    }
    // 위상정렬을 수행한 결과 출력
    for (unsigned int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
}


int main() {
    
    cin >> N >> M;

    
    for (int i = 1; i <= M; i++) {
        int x, y;
        cin >> x >> y;
        indegree[y] += 1;
        graph[x].push_back(y);
    }

    sort();

    return 0;
}