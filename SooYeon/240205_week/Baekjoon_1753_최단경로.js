let fs = require('fs');
let input = fs.readFileSync('dev/stdin').toString().split('\n');

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


// let input = `5 6
// 1
// 5 1 1
// 1 2 2
// 1 3 3
// 2 3 4
// 2 4 5
// 3 4 6`.split('\n');

let [v, e] = input[0].split(' ').map(Number);
let start = Number(input[1]);

let graph = Array.from({length: v + 1}, () => []);
let INF = 987654321;
let distance = Array(v + 1).fill(INF);

for(let i = 2; i <= e + 1; i++) {
  let [a, b, c] = input[i].split(' ').map(Number);
  graph[a].push([b, c]);
}

const dijkstra = (start) => {
  let pq = new PriorityQueue((a, b) => b[0] - a[0]); // 최소힙

  pq.enq([0, start]);
  distance[start] = 0;

  while(pq.size() != 0) {
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

dijkstra(start);

let result = distance.slice(1);

let answer = [];
result.forEach((dist) => {
  if(dist === INF) answer.push('INF');
  else answer.push(dist);
})

console.log(answer.join('\n'));