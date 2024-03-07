function solution(n, k) {
  let answer = [];

  // 모든 순열의 값을 구해서 정답을 찾으면 시간초과가 난다.
  // 팩토리얼 값을 찾아서 순열의 값을 찾는 방법을 사용한다.
  let people = Array.from({ length: n }, (_, i) => i + 1);
  let factorial = people.reduce((acc, cur) => acc * cur, 1);

  while (answer.length < n) {
    factorial = Math.floor(factorial / people.length);
    let idx = Math.floor((k - 1) / factorial);

    answer.push(...people.splice(idx, 1));
    k = k % factorial;
  }
}

return answer;
