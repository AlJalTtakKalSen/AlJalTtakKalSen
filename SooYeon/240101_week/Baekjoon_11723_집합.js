let fs = reauire('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `26
// add 1
// add 2
// check 1
// check 2
// check 3
// remove 2
// check 1
// check 2
// toggle 3
// check 1
// check 2
// check 3
// check 4
// all
// check 10
// check 20
// toggle 10
// remove 20
// check 10
// check 20
// empty
// check 1
// toggle 1
// check 1
// toggle 1
// check 1
// `.split('\n');

let m = Number(input[0]);
let arr = [];
let answer = '';

function add(x) {
  arr.push(x);
}

function remove(x) {
  arr = arr.filter((num) => num != x);
}

function check(x) {
  if(arr.includes(x)) answer += '1';
  else answer += '0';
}

function toggle(x) {
  if(arr.includes(x)) remove(x);
  else add(x);
}

function all() {
  arr = [];
  for(let i = 1; i <= 20; i++) arr.push(i);
}

function empty() {
  arr = [];
}

for(let i = 1; i <= m; i++) {
  let [command, x] = input[i].split(' ');
  if(x) x = Number(x);

  switch(command) {
    case 'add':
      add(x); break;
    case 'remove':
      remove(x); break;
    case 'check':
      check(x); break;
    case 'toggle':
      toggle(x); break;
    case 'all':
      all(); break;
    case 'empty':
      empty(); break;
  }
  if(i != m && command === 'check') answer += '\n';
}

console.log(answer);
