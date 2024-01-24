import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        // 1. 입력받기
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bf.readLine());

        // 2. 1의 개수 저장하기
        long answer = 0;
        int[] countOneBits = new int[20]; // 1,000,000의 이진 표현은 최대 20비트 필요
        for (int i = 0; i < n; i++) {
            int resident = Integer.parseInt(bf.readLine());
            for (int j = 0; j < 20; j++) { // 자리수마다
                if ((resident & (1 << j)) != 0) { // 1이 존재하면 +1
                    countOneBits[j]++;
                }
            }
        }
        // 3. 친밀도 구하기
        // XOR 값 = 0의 개수 * 1의 개수 * 비트 값
        for (int i = 0; i < 20; i++) { // 자리 수 마다 친밀도 구하기
            long zeroCount = n - countOneBits[i]; // 0의 개수
            long oneCount = countOneBits[i]; // 1의 개수
            answer += zeroCount * oneCount * (1 << i); // 비트 위치 반영하여 값 구함
        }
        // 4. 정답 출력하기
        System.out.println(answer);
    }
}