class Solution {
    public int[] solution(String[] park, String[] routes) {
        int[] position = new int[2];
        int[] answer = new int[2];
        for (int i=0;i<park.length;i++){
            for(int j=0;j<park[i].length();j++){
                if (park[i].charAt(j) == 'S'){
                    position[0] = i;
                    position[1] = j;
                }
            }
        }
        for (String route : routes){
            String[] parts = route.split(" ");
            String direction = parts[0];
            int distance = Integer.parseInt(parts[1]);

            int newY = position[0];
            int newX = position[1];
            boolean isMovable = true;

            for (int i=0;i<distance;i++){

                switch(direction){
                    case "N":newY-=1; break;
                    case "S": newY+=1; break;
                    case "E":newX+=1; break;
                    case "W":newX-=1;break;
                }

                if (newY<0 || newY>=park.length || newX<0 || newX>=park[0].length() || park[newY].charAt(newX) == 'X'){
                    isMovable = false;
                    break;
                }
            }
            if (isMovable){
                position[0] = newY;
                position[1] = newX;
            }

        }

        return position;
    }
}