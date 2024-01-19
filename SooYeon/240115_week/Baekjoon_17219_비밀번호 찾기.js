let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

// let input = `16 4
// noj.am IU
// acmicpc.net UAENA
// startlink.io THEKINGOD
// google.com ZEZE
// nate.com VOICEMAIL
// naver.com REDQUEEN
// daum.net MODERNTIMES
// utube.com BLACKOUT
// zum.com LASTFANTASY
// dreamwiz.com RAINDROP
// hanyang.ac.kr SOMEDAY
// dhlottery.co.kr BOO
// duksoo.hs.kr HAVANA
// hanyang-u.ms.kr OBLIVIATE
// yd.es.kr LOVEATTACK
// mcc.hanyang.ac.kr ADREAMER
// startlink.io
// acmicpc.net
// noj.am
// mcc.hanyang.ac.kr`.split('\n');

let [n, m] = input[0].split(' ').map(Number);

let map = {};

for(let i = 1; i <= n; i++) {
  let [site, pw] = input[i].split(' ');

  map[site] = pw;
}

let answer = [];
for(let i = n + 1; i < m + n + 1; i++) {
  let site = input[i];
  answer.push(map[site]);
}

console.log(answer.join('\n'));

