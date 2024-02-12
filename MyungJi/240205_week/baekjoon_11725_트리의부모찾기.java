package Practice;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class prac3 {

    static List<List<Integer>> list;
    static int[] parentList;

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        Integer n = Integer.parseInt(bf.readLine());

        list = new ArrayList<>(n + 1);
        parentList = new int[n + 1];

        for (int i = 0; i < n + 1; i++) {
            list.add(new ArrayList<>());
        }

        for (int i = 0; i < n-1; i++) {
            String[] input = bf.readLine().split(" ");
            int node = Integer.parseInt(input[0]);
            int parent = Integer.parseInt(input[1]);

            list.get(node).add(parent);
            list.get(parent).add(node);
        }

        dfs(1, 0); // 루트 노드부터 탐색 시작

        for (int i = 2; i <= n; i++) {
            System.out.println(parentList[i]);
        }
    }

    static void dfs(int node, int parent) {
        parentList[node] = parent;

        for (int child : list.get(node)) {
            if (child != parent) {
                dfs(child, node);
            }
        }
    }
}
