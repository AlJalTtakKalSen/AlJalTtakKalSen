let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `4 2
// 9 8 7 1`.split('\n');

let [n, m] = input[0].split(' ').map(Number);
let arr = input[1].split(' ').map(Number);

let answer = [];
const combi = (b, k) => {
  if(b.length == k) {
    let tmp = [];
    for(let i = 0; i < b.length; i++) {
      tmp.push(parseInt(arr[b[i]]));
    }
    answer.push([...tmp]);
    return;
  }

  for(let i = 0; i < n; i++) {
    if(b.includes(i)) continue;
    b.push(i);
    combi(b, k);
    b.pop(i);
  }
  return;
}

let b = [];
combi(b, m);

answer.sort((a, b) => {
  for(let i = 0; i < m; i++) {
    if(a[i] == b[i]) continue;
    return a[i] - b[i];
  }
});

console.log(answer.map(v => v.join(' ')).join('\n'));