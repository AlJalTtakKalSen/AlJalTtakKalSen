import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class prac1 {
    public static int sumInteger(int number) {
        int sum = 0;
        while (number > 0) {
            sum += number % 10;
            number /= 10;
        }
        return sum;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bf.readLine());

        for (int i = Math.max(n - 9 * String.valueOf(n).length(), 1); i < n; i++) {
            System.out.println(9 * String.valueOf(n).length());
            if (i + sumInteger(i) == n) {
                System.out.println(i);
                return;
            }
        }
        System.out.println(0);
    }
}
