import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {
    static class Pair{
        int zeroCnt;
        int oneCnt;

        public Pair(int zeroCnt, int oneCnt) {
            this.zeroCnt = zeroCnt;
            this.oneCnt = oneCnt;
        }
    }

    public static void main(String[] args) throws IOException {
        //1. 입력받기
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bf.readLine());
        //2. dp 수행
        Pair[] cnt = new Pair[41];
        cnt[0] = new Pair(1, 0);
        cnt[1] = new Pair(0, 1);
        for (int i = 2; i <= 40; i++) {
            cnt[i] = new Pair(cnt[i - 1].zeroCnt + cnt[i - 2].zeroCnt, cnt[i - 1].oneCnt + cnt[i - 2].oneCnt);
        }
        //3. 정답 출력
        while (t-- > 0) {
            int n = Integer.parseInt(bf.readLine());
            System.out.println(cnt[n].zeroCnt + " " + cnt[n].oneCnt);
        }
    }
}