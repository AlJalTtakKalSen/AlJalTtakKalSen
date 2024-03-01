class Solution {
    public int solution(String s) {
        int answer = 0;
        char c = s.charAt(0);
        int[] cnt = new int[2];
        for (char str : s.toCharArray()){
            if (cnt[1] != 0 && cnt[0] == cnt[1]){
                answer++;
                cnt[0] = cnt[1] = 0;
                c = str;
            }
            if (str == c){
                cnt[0]++;
            } else cnt[1]++;
        }
        if (cnt[0] != 0) answer++;
        return answer;
    }
}