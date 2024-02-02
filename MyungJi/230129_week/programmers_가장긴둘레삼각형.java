import java.util.Arrays;
import java.util.Collections;

class Solution {
    public int solution(int[] arr) {
        // 오름차순 정렬
        Integer[] a = Arrays.stream(arr).boxed().toArray(Integer[]::new);
        Arrays.sort(a, Collections.reverseOrder());
        // 삼각형 구하기
        int maxDiameter = 0;
        for (int i = 0; i < a.length-2; i++) {
            if (a[i] < a[i + 1] + a[i + 2]) {
                int dia = a[i] + a[i + 1] + a[i + 2];
                maxDiameter = Math.max(maxDiameter, dia);
            }
        }
        return maxDiameter;
    }
}