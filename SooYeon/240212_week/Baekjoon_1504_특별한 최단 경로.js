let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

function PriorityQueue(comparator) {
  this._comparator = comparator || PriorityQueue.DEFAULT_COMPARATOR;
  this._elements = [];
}

PriorityQueue.DEFAULT_COMPARATOR = function(a, b) {
  if (typeof a === 'number' && typeof b === 'number') {
    return a - b;
  } else {
    a = a.toString();
    b = b.toString();

    if (a == b) return 0;

    return (a > b) ? 1 : -1;
  }
};

PriorityQueue.prototype.isEmpty = function() {
  return this.size() === 0;
};

PriorityQueue.prototype.peek = function() {
  if (this.isEmpty()) throw new Error('PriorityQueue is empty');

  return this._elements[0];
};

PriorityQueue.prototype.deq = function() {
  var first = this.peek();
  var last = this._elements.pop();
  var size = this.size();

  if (size === 0) return first;

  this._elements[0] = last;
  var current = 0;

  while (current < size) {
    var largest = current;
    var left = (2 * current) + 1;
    var right = (2 * current) + 2;

    if (left < size && this._compare(left, largest) >= 0) {
      largest = left;
    }

    if (right < size && this._compare(right, largest) >= 0) {
      largest = right;
    }

    if (largest === current) break;

    this._swap(largest, current);
    current = largest;
  }

  return first;
};

PriorityQueue.prototype.enq = function(element) {
  var size = this._elements.push(element);
  var current = size - 1;

  while (current > 0) {
    var parent = Math.floor((current - 1) / 2);

    if (this._compare(current, parent) <= 0) break;

    this._swap(parent, current);
    current = parent;
  }

  return size;
};

PriorityQueue.prototype.size = function() {
  return this._elements.length;
};

PriorityQueue.prototype.forEach = function(fn) {
  return this._elements.forEach(fn);
};

PriorityQueue.prototype._compare = function(a, b) {
  return this._comparator(this._elements[a], this._elements[b]);
};

PriorityQueue.prototype._swap = function(a, b) {
  var aux = this._elements[a];
  this._elements[a] = this._elements[b];
  this._elements[b] = aux;
};

// let input = `4 6
// 1 2 3
// 2 3 3
// 3 4 1
// 1 3 5
// 2 4 5
// 1 4 4
// 2 3`.split('\n');

let [n, e] = input[0].split(' ').map(Number);
let graph = Array.from({length: n + 1}, () => []);

for(let i = 1; i <= e; i++) {
  let [a, b, c] = input[i].split(' ').map(Number);

  // 양방향 그래프
  graph[a].push([b, c]);
  graph[b].push([a, c]);
}

let [v1, v2] = input[e + 1].split(' ').map(Number);
let INF = 1e9;
let distance = new Array(n + 1).fill(INF); // 최단 거리 테이블 무한으로 초기화

const dijkstra = (start) => {
  let pq = new PriorityQueue((a, b) => b[0] - a[0]); // 최소힙
  // 시작 노드로 가기 위한 최단 거리는 0으로 우선순위 큐에 삽입
  pq.enq([0, start]);
  distance[start] = 0;

  while(pq.size()) {
    // 가장 최단 거리가 짧은 노드에 대한 정보 꺼내기
    let [dist, now] = pq.deq();

    // 현재 노드가 이미 처리된 적이 있는 노드라면 무시
    if(distance[now] < dist) continue;

    for(let i of graph[now]) {
      let cost = dist + i[1];

      // 현재 노드(now)를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
      if(cost < distance[i[0]]) {
        distance[i[0]] = cost;
        pq.enq([cost, i[0]]);
      }
    }
  }
}

let answer = -1;
// 1 -> v1 -> v2 -> n
// 1 -> v2 -> v1 -> n
dijkstra(1);
let oneToV1 = distance[v1]; // 1 -> v1
let oneToV2 = distance[v2]; // 1 -> v2

// 초기화
distance.fill(INF);
dijkstra(v1);
let v1ToV2 = distance[v2]; // v1 -> v2
let v1ToN = distance[n]; // v1 -> n

// 초기화
distance.fill(INF);
dijkstra(v2);
let v2ToV1 = distance[v1]; // v2 -> v1
let v2ToN = distance[n]; // v2 -> n

let route1 = oneToV1 + v1ToV2 + v2ToN;
let route2 = oneToV2 + v2ToV1 + v1ToN;

if(route1 < INF && route2 < INF) {
  answer = Math.min(route1, route2);
}

console.log(answer);