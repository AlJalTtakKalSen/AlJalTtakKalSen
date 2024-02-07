import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        Integer result = Integer.parseInt(bf.readLine());

        while (true) {
            String input = bf.readLine();
            if (input.equals("=")) {
                break;
            } else if (input.equals("+")) {
                result += Integer.parseInt(bf.readLine());
            } else if (input.equals("-")) {
                result -= Integer.parseInt(bf.readLine());
            } else if (input.equals("*")) {
                result *= Integer.parseInt(bf.readLine());
            } else if (input.equals("/")) {
                result /= Integer.parseInt(bf.readLine());
            }
        }
        System.out.println(result);
    }
}
