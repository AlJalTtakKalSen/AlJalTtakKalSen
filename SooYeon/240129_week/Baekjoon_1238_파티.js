// let fs = require('fs');
// let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// 우선순위 큐
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
// 우선순위 큐 end

let input = `4 8 2
1 2 4
1 3 2
1 4 7
2 1 1
2 3 5
3 1 2
3 4 4
4 2 3`.split('\n');

let [n, m, x] = input[0].split(' ').map(Number);

// [] 마을에서 X 마을로 가는 최단거리 리스트 중 가장 큰 값
// X 마을에서 [] 마을로 가는 최단거리 리스트 중 가장 큰 값

let graph = Array.from({length: n + 1}, () => []);
let INF = 987654321;
let distance = Array(n + 1).fill(INF);

for(let i = 1; i <= m; i++) {
  let [start, end, weight] = input[i].split(' ').map(Number);
  graph[start].push([end, weight]);
}

const dijkstra = (start) => {
  let pq = new PriorityQueue((a, b) => b[0] - a[0]); // 최소힙
  pq.enq([0, start]); // 시작 노드로 가기 위한 최단 거리는 0으로 설정
  distance[start] = 0;

  while(pq.size() != 0) {
    // 가장 최단 거리가 짧은 노드에 대한 정보 꺼내기
    let [dist, now] = pq.deq();
    if(distance[now] < dist) continue;

    for(let node of graph[now]) {
      let cost = dist + node[1];

      if(cost < distance[node[0]]) {
        distance[node[0]] = cost;
        pq.enq([cost, node[0]]);
      }
    }
  }
}

dijkstra(x); // x 마을에서 [] 마을로 가는 최단 거리
let result = distance.slice(1);

for(let i = 1; i <= n; i++) {
  distance.fill(INF);
  dijkstra(i); // [] 마을에서 X 마을로 가는 최단 거리
  result[i - 1] += distance[x]; // x 마을 -> [] 마을 + [] 마을 -> x 마을
}

console.log(Math.max(...result));