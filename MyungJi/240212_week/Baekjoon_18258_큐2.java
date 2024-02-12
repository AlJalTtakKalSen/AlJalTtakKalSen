import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class prac9 {

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bf.readLine());
        Queue<Integer> queue = new LinkedList<>();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            String[] input = bf.readLine().split(" ");
            switch (input[0]){
                case "push":
                    queue.offer(Integer.parseInt(input[1]));
                    break;
                case "pop":
                    if (queue.isEmpty()) sb.append("-1\n");
                    else sb.append(queue.poll() + "\n");
                    break;
                case "size":
                    sb.append(queue.size() + "\n");
                    break;
                case "empty":
                    if (queue.isEmpty()) sb.append("1\n");
                    else sb.append("0\n");
                    break;
                case "front":
                    if (queue.isEmpty()) sb.append("-1\n");
                    else sb.append(queue.peek() + "\n");
                    break;
                case "back":
                    if (queue.isEmpty()) sb.append("-1\n");
                    else sb.append(((LinkedList<Integer>) queue).getLast() + "\n");
                    break;
            }
        }
        System.out.println(sb.toString());
    }
}