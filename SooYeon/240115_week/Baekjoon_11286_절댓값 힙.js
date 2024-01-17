let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `18
// 1
// -1
// 0
// 0
// 0
// 1
// 1
// -1
// -1
// 2
// -2
// 0
// 0
// 0
// 0
// 0
// 0
// 0`.split('\n');

module.exports = PriorityQueue;

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

/**
 *  Iterates over queue elements
 *
 *  @param {Function} fn
 */
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

// x가 0이 아니라면 x라는 값을 추가하는 연산
// x가 0이라면 배열에서 절댓값이 가장 작은 값을 출력, 그 값을 배열에서 제거
// 배열이 비어있는 경우의 출력 값은 0

let n = Number(input[0]);
let queue = new PriorityQueue((a, b) => {
  if(a.abs === b.abs) return b.original - a.original;
  else return b.abs - a.abs;
});

let answer = [];
for(let i = 1; i <= n; i++) {
  let x = Number(input[i]);

  if(x !== 0) {
    // insert
    queue.enq({original: x, abs: Math.abs(x)});
  }
  else {
    // 절댓값이 가장 작은 값을 출력, 제거
    if(queue.size()) {
      answer.push(queue.peek().original);
      queue.deq();
    } else {
      answer.push(0);
    }
  }
}

console.log(answer.join('\n'));