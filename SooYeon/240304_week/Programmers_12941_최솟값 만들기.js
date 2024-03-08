// 두 배열에서 원소를 뽑아 더한 값이 최소가 되기 위한 방법
// 최소값 * 최댓값 들을 더한 최종 값
function solution(A, B) {
  let arr = [];

  A = A.sort((a, b) => b - a); // 내림차순
  B = B.sort((a, b) => a - b); // 오름차순

  for (let i = 0; i < A.length; i++) {
    arr.push(A[i] * B[i]);
  }

  let answer = arr.reduce((acc, v) => acc + v, 0);

  return answer;
}
