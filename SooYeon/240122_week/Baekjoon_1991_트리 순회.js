let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `7
// A B C
// B D .
// C E F
// E . .
// F . G
// D . .
// G . .`.split('\n');

// 전위, 중위, 후위 순회
let n = Number(input[0]);

let tree = {};
for(let i = 1; i <= n; i++) {
  let arr = input[i].split(' ');
  for(let j = 0; j < 3; j++) {
      tree[arr[0]] = [arr[1], arr[2]];
    }
}

let pre = [];
const preFunc = (node) => {
  pre.push(node);
  // 왼쪽 자식
  tree[node][0] != '.' ? preFunc(tree[node][0]) : null;
  // 오른쪽 자식
  tree[node][1] != '.' ? preFunc(tree[node][1]) : null;
  return;
}

let ino = [];
const inFunc = (node) => {
  // 왼쪽 자식
  tree[node][0] != '.' ? inFunc(tree[node][0]) : null;
  ino.push(node);
  //오른쪽 자식
  tree[node][1] != '.' ? inFunc(tree[node][1]) : null;

  return;
}

let post = [];
const postFunc = (node) => {
  // 왼쪽 자식
  tree[node][0] != '.' ? postFunc(tree[node][0]) : null;
  // 오른쪽 자식
  tree[node][1] != '.' ? postFunc(tree[node][1]) : null;
  post.push(node);

  return;
}

preFunc('A');
inFunc('A');
postFunc('A');

let answer = pre.join('') + '\n' + ino.join('') + '\n' + post.join('');
console.log(answer);