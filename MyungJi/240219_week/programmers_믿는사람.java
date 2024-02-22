import java.util.HashMap;
class Solution {
    public int solution(int N, int[][] trust) {
        int answer = 0;
        HashMap<Integer, Integer> trusts = new HashMap<>();
        HashMap<Integer, Integer> trustedBy = new HashMap<>();

        for (int[] relation:trust){
            trusts.put(relation[0], trusts.getOrDefault(relation[0], 0)+1);
            trustedBy.put(relation[1], trustedBy.getOrDefault(relation[1],0)+1);
        }
        for (int i=1;i<=N;i++){
            if (trustedBy.getOrDefault(i, 0) == N-1 && !trusts.containsKey(i)){
                return i;
            }
        }
        return -1;
    }
}