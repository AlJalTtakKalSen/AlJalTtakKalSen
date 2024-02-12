import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String input = bf.readLine();
        String[] array = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
        for (String a : array) {
            input = input.replace(a, "1");
        }
        System.out.println(input.length());

    }

}
