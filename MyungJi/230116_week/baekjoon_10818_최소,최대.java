import java.util.Scanner;

public class prac1 {
    public static void main(String[] args) {
        // 입력받기
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        // 최대값 구하기
        int value = 0;
        int maxValue = Integer.MIN_VALUE, minValue = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            value = sc.nextInt();
            if (value > maxValue) {
                maxValue = value;
            }
            if (value < minValue) {
                minValue = value;
            }
        }
        // 정답 출력
        System.out.print(minValue + " ");
        System.out.println(maxValue);
    }
}