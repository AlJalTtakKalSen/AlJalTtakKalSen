import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.stream.IntStream;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String[] inputs = bf.readLine().split(" ");
        int n = Integer.parseInt(inputs[0]);
        int k = Integer.parseInt(inputs[1]);

        Queue queue = new LinkedList();
        ArrayList result = new ArrayList();

        IntStream.range(1, n + 1).forEach(x -> queue.add(x));
        int cnt = 0;
        while (!queue.isEmpty()) {
            int data = (int) queue.remove();
            cnt++;

            if (cnt % k == 0) {
                result.add(data);
            } else {
                queue.add(data);
            }
        }
        System.out.print("<");
        for (int i = 0; i < result.size(); i++) {
            System.out.print(result.get(i));
            if (i != result.size() - 1) {
                System.out.print(", ");
            }
        }
        System.out.print(">");

    }

}
