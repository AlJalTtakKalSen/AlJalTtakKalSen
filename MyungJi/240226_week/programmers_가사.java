import java.util.HashMap;
import java.util.ArrayList;

class Solution {
    public String[][] solution(String[] titles, String[] lyrics, String[] problems) {
        String[][] answer = new String[problems.length][];

        ArrayList<ArrayList<String>> list = new ArrayList<>();
        for (int i=0;i<problems.length;i++){
            ArrayList tmp = new ArrayList<>();
            for (int j=0;j<titles.length;j++){
                if (lyrics[j].startsWith(problems[i]))
                    tmp.add(titles[j]);
            }
            list.add(tmp);
        }
        for (int i=0;i<problems.length;i++){
            ArrayList<String> row = list.get(i);
            answer[i] = row.toArray(new String[row.size()]);
        }
        return answer;
    }
}