import java.util.PriorityQueue;
import java.util.Collections;

class Solution {
    public int solution(int[] cards) {
        int answer = 0;
        // 내림차순 정렬
        PriorityQueue<Integer> queue = new PriorityQueue<Integer>(Collections.reverseOrder());
        for (int c:cards) queue.offer(c);
        // 게임 수행
        while (!queue.isEmpty()){
            if (queue.size()==1) return queue.poll();
            int a = queue.poll();
            int b = queue.poll();
            if (a==b) continue;
            else queue.offer(Math.abs(a-b));
        }
        return answer;
    }
}