class Solution {
    public int solution(int n, int m, int[] section) {
        int answer = 1;
        int pos = section[0];
        for (int i=1;i<section.length;i++){
            if (pos+m-1 < section[i]){
                answer++;
                pos = section[i];
            }
        }

        return answer;
    }
}