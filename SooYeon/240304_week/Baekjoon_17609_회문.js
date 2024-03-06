let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `7
// abba
// summuus
// xabba
// xabbay
// comcom
// comwwmoc
// comwwtmoc`.split('\n');

// 회문: 0
// 유사 회문: 1
// 그 외: 2
let testCase = Number(input[0]);

const checkPalindrome = (s) => {
  return s === [...s].reverse().join('') ? true : false;
}

let answer = [];
let left, right, tmp, check;
for(let t = 1; t <= testCase; t++) {
  let str = input[t];

  if(checkPalindrome(str)) answer.push(0);
  else {
    check = false;
    for(let i = 0; i < str.length / 2; i++) {
      if(str[i] !== str[str.length - i - 1]) {
        // 왼쪽 문자 제거
        left = str.slice(0, i);
        right = str.slice(i + 1);
        tmp = left + right;

        if(checkPalindrome(tmp)) check = true;
        else {
           // 오른쪽 문자 제거
          left = str.slice(0, str.length - i - 1);
          right = str.slice(str.length - i);
          tmp = left + right;

          if(checkPalindrome(tmp)) check = true;
        }
        break;
      }
    }
    if(check) answer.push(1);
    else answer.push(2);
  }
}

console.log(answer.join('\n'));