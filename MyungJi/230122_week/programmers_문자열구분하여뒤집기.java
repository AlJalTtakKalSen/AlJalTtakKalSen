import java.util.ArrayList;

class Solution {
    public String[] solution(String s) {
        ArrayList<String> answerList = new ArrayList<>();

        String[] parts = s.split("[.,!? ]+");
        for(String part : parts){
            if (part.length() == 0) continue;
            StringBuilder sb = new StringBuilder(part);
            sb.reverse();
            answerList.add(sb.toString());
        }
        return answerList.toArray(new String[0]);
    }
}