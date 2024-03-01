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

// let input = `5
// 8
// 1 2 2
// 1 3 3
// 1 4 1
// 1 5 10
// 2 4 2
// 3 4 1
// 3 5 1
// 4 5 3
// 1 5`.split('\n');

let n = Number(input[0]);
let m = Number(input[1]);
let graph = Array.from({length: n + 1}, () => []);

for(let i = 2; i < m + 2; i++) {
  let [a, b, c] = input[i].split(' ').map(Number);
  graph[a].push([b, c]);
}

let [start, end] = input[m + 2].split(' ').map(Number);

let INF = 1e9;
let distance = Array(n + 1).fill(INF);
let way = Array(n + 1).fill(-1);

const dijkstra = (start) => {
  let queue = new PriorityQueue((a, b) => b[0] - a[0]);
  
  queue.enq([0, start]);
  distance[start] = 0;
  way[start] = start;

  while(queue.size()) {
    // 가장 최단 거리가 짧은 노드에 대한 정보 꺼내기
    let [dist, now] = queue.deq();

    // 현재 노드가 이미 처리된 적이 있는 노드라면 무시
    if(distance[now] < dist) continue;

    for(let i of graph[now]) {
      let cost = dist + i[1];

      if(cost < distance[i[0]]) {
        distance[i[0]] = cost;
        queue.enq([cost, i[0]]);
        way[i[0]] = now;
        // console.log(now, '노드에서', i[0], '노드로 가는 비용:', cost, '현재까지 최단거리:', distance);
      }
    }
  }
}

dijkstra(start);

let path = [end];
let parent = way[end];
while(parent !== start) {
  path.push(parent);
  parent = way[parent];
}

path.push(start);
path.reverse();

let answer = '';
answer += distance[end] + '\n';
answer += path.length + '\n';
answer += path.join(' ');

console.log(answer);