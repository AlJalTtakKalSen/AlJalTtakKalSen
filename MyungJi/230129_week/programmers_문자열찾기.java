lass Solution {
public int solution(String[] array, String s) {
    int answer = 0;
    for (String a:array){
    boolean isAnswer = true;
    if (a.length()>s.length()) continue;
    for (int i=0;i<a.length();i++){
    if (a.charAt(i)!=s.charAt(i)){
    isAnswer = false;
    break;
    }
    }
    if (isAnswer) answer++;
    }
    return answer;
    }
    }