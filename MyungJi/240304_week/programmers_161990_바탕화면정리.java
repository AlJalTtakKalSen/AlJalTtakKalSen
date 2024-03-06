import java.util.ArrayList;

class Solution {
    public int[] solution(String[] wallpaper) {
        ArrayList<Integer> answer = new ArrayList<>();
        int maxNum = 54;
        int lux = maxNum, luy = maxNum, rdx = 0, rdy = 0;
        for (int i=0;i<wallpaper.length;i++){
            for (int j=0;j<wallpaper[i].length();j++){
                if (wallpaper[i].charAt(j) == '#'){
                    lux = Math.min(i, lux);
                    luy = Math.min(j, luy);
                    rdx = Math.max(i, rdx);
                    rdy = Math.max(j, rdy);
                }
            }
        }
        answer.add(lux);
        answer.add(luy);
        answer.add(rdx+1);
        answer.add(rdy+1);

        return answer.stream().mapToInt(x->x).toArray();
    }
}