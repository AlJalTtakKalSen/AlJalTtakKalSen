import java.util.HashMap;
import java.util.ArrayList;
class Solution {
    public int[] solution(String[] name, int[] yearning, String[][] photo) {
        ArrayList<Integer> answer = new ArrayList<>();
        HashMap<String, Integer> mp = new HashMap<>();
        for(int i=0;i<name.length;i++){
            mp.put(name[i], yearning[i]);
        }
        for (int i=0;i<photo.length;i++){
            int total = 0;
            for (int j=0;j<photo[i].length;j++){
                total += mp.getOrDefault(photo[i][j], 0);
            }
            answer.add(total);
        }
        return answer.stream().mapToInt(x->x).toArray();
    }
}