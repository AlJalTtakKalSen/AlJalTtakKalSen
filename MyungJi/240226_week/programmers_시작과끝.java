import java.util.ArrayList;

class Solution {
    private int countMatches(String[] words, String query, boolean startsWith){
        int cnt = 0;
        for (String w : words){
            if (startsWith ? w.startsWith(query) : w.endsWith(query)){
                cnt++;
            }
        }
        return cnt;
    }

    public int[] solution(String[] words, String[] queries) {
        ArrayList<Integer> answer = new ArrayList<>();
        for (String query : queries){
            int cnt = 0;
            if (query.charAt(0) == '*'){
                query = query.substring(1, query.length());
                cnt = countMatches(words, query, false);
            } else {
                query = query.substring(0, query.length()-1);
                cnt = countMatches(words, query, true);
            }
            answer.add(cnt);
        }
        return answer.stream().mapToInt(x->x).toArray();
    }
}