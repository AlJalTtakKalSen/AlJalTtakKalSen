import java.util.HashMap;
import java.util.Map;
import java.util.ArrayList;
import java.util.Collections;


class Solution {
    public String solution(String s) {
        String answer = "";
        ArrayList<String> list = new ArrayList<String>();
        HashMap<String, Integer> hm = new HashMap<>();
        for (String str: s.split("")){
            hm.put(str, hm.getOrDefault(str, 0) + 1);
        }
        for (Map.Entry<String, Integer> kv : hm.entrySet()){
            if (kv.getValue() == 1) list.add(kv.getKey());
        }
        Collections.sort(list);
        for (String str : list){
            answer += str;
        }
        return answer;
    }
}