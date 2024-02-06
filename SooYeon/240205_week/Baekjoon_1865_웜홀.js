let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `2
// 3 3 1
// 1 2 2
// 1 3 4
// 2 3 1
// 3 1 3
// 3 2 1
// 1 2 3
// 2 3 4
// 3 1 8`.split('\n');

let testCase = Number(input[0]);
let line = 1;
let answer = [];
let INF = 987654321;

for (let i = 0; i < testCase; i++) {
  let [n, m, w] = input[line].split(' ').map(Number);
  line++;
  let graph = Array.from((n + w + 1), () => []);
  let dist = Array(n + 1).fill(INF);
  let isCycle = false;

  for (let j = 0; j < m; j++) {
    let [s, e, t] = input[line + j].split(' ').map(Number);
    graph.push([s, e, t]);
    graph.push([e, s, t]);
  }
  line += m;

  for(let j = 0; j < w; j++) {
    let [s, e, t] = input[line + j].split(' ').map(Number);
    graph.push([s, e, -t]);
  }
  line += w;

  const bellmanFord = (start) => {
    let updated = false;
    // 시작 노드에 대해서 초기화
    dist[start] = 0;
    // 전체 n번의 라운드를 반복
    for(let j = 1; j <= n; j++) {
      updated = false;
      // 매 반복마다 모든 간선을 확인하며
      for(let k = 0; k < graph.length; k++) {
        // 출발 노드, 도착 노드, 비용
        let [cur, nextNode, cost] = graph[k];
        // 현재 간선을 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
        if(dist[cur] != INF && dist[nextNode] > dist[cur] + cost) {
          dist[nextNode] = dist[cur] + cost;
          updated = true;
        }
      }
      // 매 라운드마다 갱신된 값이 없다면 중지
      if(!updated) return false;
      if(updated && j == n) return true;
    }
  }

  for(let j = 1; j <= n; j++) {
    if(bellmanFord(j)) {
      isCycle = true;
      break;
    }
  }

  answer.push(isCycle ? 'YES' : 'NO');
}

console.log(answer.join('\n'));