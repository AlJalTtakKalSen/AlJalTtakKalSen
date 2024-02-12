import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class prac3 {

    public static int cnt = 0, target = 0;
    public static int[] output;
    public static boolean isOut = false;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int num = Integer.parseInt(st.nextToken());
        target = Integer.parseInt(st.nextToken());
        int[] arr = new int[num + 1];
        arr[0] = 0;
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i < arr.length; i++) arr[i] = Integer.parseInt(st.nextToken());
        heapSort(arr);
        if (!isOut) {
            System.out.print(-1);
        }
    }

    public static void swap (int[] arr, int a, int b){
        cnt++;
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
        if(cnt == target){
            StringBuilder sb = new StringBuilder();
            for (int i = 1; i < arr.length; i++) {
                sb.append(arr[i]);
                sb.append(" ");
            }
            System.out.print(sb.toString());
            isOut = true;
        }
    }

    public static void heapSort(int[] arr) {
        buildMinHeap(arr, arr.length - 1);
        for (int i = arr.length - 1; i > 1 ; i--) {
            swap(arr, 1 , i);
            heapify(arr, 1, i - 1);
        }
    }

    public static void buildMinHeap(int[] arr, int num) {
        for (int i = num / 2; i >= 1 && !isOut; i--) {
            heapify(arr, i, num);
        }
    }

    public static void heapify(int[] arr, int k, int num) {
        int left = 2 * k;
        int right = 2 * k + 1;
        int smaller = -1;

        if (right <= num) {
            smaller = arr[left] < arr[right] ? left : right;
        } else if (left <= num) {
            smaller = left;
        } else {
            return;
        }

        if (arr[smaller] < arr[k]) {
            swap(arr,k,smaller);
            heapify(arr, smaller, num);
        }
    }
}