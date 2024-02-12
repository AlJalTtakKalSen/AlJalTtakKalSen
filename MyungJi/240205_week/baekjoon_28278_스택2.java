package Practice;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class prac4 {
    static Stack<Integer> stack;
    public static void work(String s, StringBuilder sb){
        switch(s){
            case "2":
                if (stack.isEmpty())
                    sb.append("-1\n");
                else
                    System.out.println(stack.pop());
                break;
            case "3":
                System.out.println(stack.size());
                break;
            case "4":
                if (stack.isEmpty())
                    sb.append("1\n");
                else
                    sb.append("0\n");
                break;
            case "5":
                if (stack.isEmpty())
                    sb.append("-1\n");
                else
                    System.out.println(stack.peek());
                break;
        }
    }

    public static void work(String s1, String s2){
        switch(s1){
            case "1":
                stack.push(Integer.parseInt(s2));
                break;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bf.readLine());
        stack = new Stack<>();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            String[] input = bf.readLine().split(" ");
            if (input.length == 1){
                work(input[0], sb);
            }
            else{
                work(input[0], input[1]);
            }
        }
        System.out.println(sb.toString());
    }

}
