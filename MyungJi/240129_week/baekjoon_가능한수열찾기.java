import java.util.ArrayList;
import java.util.Stack;

public class Main {
    public static void solution(int[] nums) {
        Stack<Integer> stack = new Stack<>();
        ArrayList<String> result = new ArrayList<>();

        int idx = 0;
        for (int i = 0; i < nums.length; i++) {
            int num = nums[i];

            if (num > idx) { // 계속 증가시킴
                for (int j = idx + 1; j < num + 1; j++) {
                    stack.push(j);
                    result.add("+");
                }
                idx = num;
            } else if (stack.peek() != num) { // 찾는 숫자가 아니면 NO
                System.out.println("NO");
                return;
            }
            stack.pop();
            result.add("-");
        }
        for (String item : result) {
            System.out.println(item);
        }
    }

    public static void main(String[] args) {
        int[] nums = {4, 3, 6, 8, 7, 5, 2, 1};
        solution(nums);

        System.out.println("=====");
        nums = new int[]{1, 2, 5, 3, 4};
        solution(nums);
    }
}
