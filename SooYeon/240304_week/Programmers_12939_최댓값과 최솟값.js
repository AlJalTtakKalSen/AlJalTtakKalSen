function solution(s) {
  let answer = "";
  let arr = [];

  arr = s.split(" ").map(Number);

  let min = Math.min(...arr);
  let max = Math.max(...arr);

  answer = min + " " + max;

  return answer;
}
