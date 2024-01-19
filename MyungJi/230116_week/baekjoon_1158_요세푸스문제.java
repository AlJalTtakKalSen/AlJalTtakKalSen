package Practice;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.stream.IntStream;

public class prac2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");

        int N = Integer.parseInt(input[0]);
        int K = Integer.parseInt(input[1]);

        Queue queue = new LinkedList<Integer>();
        IntStream.range(1, N + 1).forEach(queue::add);

        ArrayList result = new ArrayList();
        int cnt = 0;
        while (!queue.isEmpty()) {
            int data = (int) queue.remove();
            cnt++;

            if (cnt % K == 0) {
                result.add(data);
            } else queue.add(data);
        }

        System.out.print("<");
        for (int i = 0; i < result.size() - 1; i++) {
            System.out.print(result.get(i) + ", ");
        }
        System.out.print(result.get(result.size() - 1));
        System.out.print(">");
    }
}
