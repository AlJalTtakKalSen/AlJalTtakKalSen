import java.util.HashMap;
import java.util.Map;

class Solution {
    public String[] solution(String[] players, String[] callings) {
        String[] answer = new String[players.length];
        HashMap<String, Integer> nameOrder = new HashMap<>();
        for (int i=0;i<players.length;i++){
            nameOrder.put(players[i], i);
        }

        for (String callingName:callings){
            int num = nameOrder.get(callingName);
            // 바꿔주기
            String frontName = players[num-1];
            players[num-1] = callingName;
            players[num] = frontName;

            // 갱신
            nameOrder.put(callingName, num-1);
            nameOrder.put(frontName, num);
        }

        return players;
    }
}