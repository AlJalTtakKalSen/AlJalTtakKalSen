class Solution {
    public int solution(int[] A) {
        int first = 1000004;
        int last = 0;
        for (int i=0;i<A.length-1;i++){
            if (A[i]<A[i+1]){
                first = Math.min(first,A[i]);
                last = Math.max(A[i+1], last);
            }
        }
        if (first == 1000004) return 0;
        else return last - first;
    }
}