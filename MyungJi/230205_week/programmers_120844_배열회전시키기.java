import java.util.Deque;
import java.util.LinkedList;
import java.util.ArrayList;

class Solution {
    public int[] solution(int[] numbers, String direction) {
        Deque<Integer> deque = new LinkedList<Integer>();
        if (direction.equals("right")){
            for (int i=0;i<numbers.length-1;i++){
                deque.addLast(numbers[i]);
            }
            deque.addFirst(numbers[numbers.length-1]);
        } else { // left
             for (int i=1;i<numbers.length;i++){
                deque.addLast(numbers[i]);
            }
            deque.addLast(numbers[0]);
        }
        
        return deque.stream().mapToInt(x->x).toArray();
    }
}