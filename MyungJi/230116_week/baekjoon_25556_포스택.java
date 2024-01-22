package Practice;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());

        int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());

        System.out.println(canCleanPermutation(arr) ? "NO" : "YES");
    }

    private static boolean canCleanPermutation(int[] permutation) {
        Stack<Integer>[] stacks = new Stack[4];
        for (int i = 0; i < 4; i++) {
            stacks[i] = new Stack<>();
        }

        int current = 1; 

        for (int num : permutation) {
            boolean placed = false;
            for (Stack<Integer> stack : stacks) {
                if (stack.isEmpty() || (!stack.isEmpty() && stack.peek() > num)) {
                    stack.push(num);
                    placed = true;
                    break;
                }
            }

            if (!placed) return false; 

            boolean progress = true;
            while (progress) {
                progress = false;
                for (Stack<Integer> stack : stacks) {
                    if (!stack.isEmpty() && stack.peek() == current) {
                        stack.pop();
                        current++;
                        progress = true;
                        break; 
                    }
                }
            }
        }

        return current == permutation.length + 1; 
    }
}
