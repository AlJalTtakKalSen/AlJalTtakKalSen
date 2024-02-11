import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;

public class prac5 {

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bf.readLine());
        Deque<Integer> deque = new ArrayDeque<>();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            String[] input = bf.readLine().split(" ");
            if (input.length == 1){
                switch(input[0]){
                    case "3":
                        if (deque.isEmpty()) {
                            sb.append("-1\n");
                        } else sb.append(deque.removeFirst()+"\n");
                        break;
                    case "4":
                        if (deque.isEmpty()) {
                            sb.append("-1\n");
                        } else sb.append(deque.removeLast()+"\n");
                        break;
                    case "5":
                        sb.append(deque.size() + "\n");
                        break;
                    case "6":
                        if (deque.isEmpty()) {
                            sb.append("1\n");
                        } else {
                            sb.append("0"+ "\n");
                        }
                        break;
                    case "7":
                        if (deque.isEmpty()) {
                            sb.append("-1\n");
                        } else sb.append(deque.peekFirst() + "\n");
                        break;
                    case "8":
                        if (deque.isEmpty()) {
                            sb.append("-1\n");
                        } else sb.append(deque.peekLast() + "\n");
                        break;
                }
            } else {
                switch(input[0]){
                    case "1":
                        deque.addFirst(Integer.parseInt(input[1]));
                        break;
                    case "2":
                        deque.addLast(Integer.parseInt(input[1]));
                        break;
                }
            }
        }
        System.out.println(sb.toString());
    }
}