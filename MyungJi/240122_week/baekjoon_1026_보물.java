import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class prac5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // N, A, B 입력 받기
        int N = sc.nextInt();
        Integer[] A = new Integer[N];
        Integer[] B = new Integer[N];

        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }

        for (int i = 0; i < N; i++) {
            B[i] = sc.nextInt();
        }

        // A 배열을 오름차순으로 정렬
        Arrays.sort(A);

        // B 배열을 내림차순으로 정렬
        Arrays.sort(B, Collections.reverseOrder());

        // S 계산
        int S = 0;
        for (int i = 0; i < N; i++) {
            S += A[i] * B[i];
        }

        // 결과 출력
        System.out.println(S);
    }
}