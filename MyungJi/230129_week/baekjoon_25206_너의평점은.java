package Practice;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class prac11 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        HashMap<String, Double> mp = new HashMap<>();
        mp.put("A+", 4.5);
        mp.put("A0", 4.0);
        mp.put("B+", 3.5);
        mp.put("B0", 3.0);
        mp.put("C+", 2.5);
        mp.put("C0", 2.0);
        mp.put("D+", 1.5);
        mp.put("D0", 1.0);
        mp.put("F", 0.0);
        double sum = 0;
        int cnt = 0;
        while ((line = br.readLine()) != null) {
            String[] stringArray = line.split(" ");
            if (stringArray[2].equals("P")) continue;
            sum += Double.parseDouble(stringArray[1]) * mp.get(stringArray[2]);
            cnt++;
        }
        double average = sum / cnt;
        System.out.printf("average = %.6f\n", average);

    }

}