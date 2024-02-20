let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trimEnd().split('\n');

// let input = `50
// 30
// 24
// 5
// 28
// 45
// 98
// 52
// 60`.split('\n');

let postOrder = input.splice(0).map(Number);
let tree = [];

// 후위 순회 트리 재구성
const makeTree = (start, end) => {
  if(start > end) return;

  // 현재 서브트리의 루트 노드
  let root = postOrder[start];
  let idx = start + 1; // 루트 노드 다음 노드부터 시작

  while(idx <= end) {
    // 루트 노드보다 큰 값이 나오면 오른쪽 서브트리라는 것이므로 break
    if(postOrder[idx] > root) break;
    idx++;
  }

  // 왼쪽 서브 트리 재구성
  makeTree(start + 1, idx - 1);
  // 오른쪽 서브 트리 재구성
  makeTree(idx, end);
  // 루트 노드 트리에 추가
  tree.push(root);
}

makeTree(0, postOrder.length - 1);
console.log(tree.join('\n'));