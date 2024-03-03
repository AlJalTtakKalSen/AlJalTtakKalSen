// Practice4
// 2차원 배열 board 가 주어졌다.
// 해당 배열 데이터에는 'o', '#', '.' 의 정보가 기입되어 있다.
// 'o': 동전을 의미
// '#': 벽을 의미
// '.': 빈칸을 의미

// 동전은 항상 두개가 주어진다.
// 두 동전이 함께 이동하다가 하나가 보드에서 떨어지는 경우의 최소 이동 횟수를 출력하는 프로그램을 작성하세요.
// 단, 이동 규칙은 다음과 같다.
// 동전은 좌, 우, 위, 아래로 이동 가능하며 같은 방향으로 함께 이동
// 빈칸이나 동전이 있는 칸으로는 이동 가능
// 벽일 때는 이동 불가
// 이동 횟수가 10번을 넘으면 중지하고 -1 반환

// 입출력 예시
// board: {{'.', '#'}, {'.', '#'}, {'.', '#'}, {'o', '#'}, {'o', '#'}, {'#', '#'}}
// 결과: 4


import java.util.ArrayList;

public class Practice4 {
    final static int[][] dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    static int cnt;

    static class Coin {
        int x;
        int y;

        public Coin(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void solution(char[][] board) {
        if (board == null || board.length == 0 || board[0].length == 0) {
            return;
        }
        int n = board.length; // y 길이
        int m = board[0].length; // x 길이
        cnt = Integer.MAX_VALUE;

        ArrayList<Coin> coins = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'o') {
                    coins.add(new Coin(j, i)); // y, x
                }
            }
        }

        Coin coin1 = coins.get(0);
        Coin coin2 = coins.get(1);
        // backTracking
        backTracking(board, n, m, coin1.x, coin1.y, coin2.x, coin2.y, 0);
        System.out.println(cnt == Integer.MAX_VALUE ? -1 : cnt);
    }

    public static void backTracking(char[][] board, int n, int m, int x1, int y1, int x2, int y2, int moveCnt) {
        if (moveCnt >= 10) { // 가지치기
            return;
        }

        for (int[] dir : dirs) {
            int x1Next = x1 + dir[0];
            int y1Next = y1 + dir[1];

            int x2Next = x2 + dir[0];
            int y2Next = y2 + dir[1];

            int dropCnt = 0;

            if (x1Next < 0 || x1Next >= m || y1Next < 0 || y1Next >= n) {
                dropCnt++;
            }

            if (x2Next < 0 || x2Next >= m || y2Next < 0 || y2Next >= n) {
                dropCnt++;
            }

            if (dropCnt == 2) {
                continue;
            }
            if (dropCnt == 1) {
                cnt = Math.min(cnt, moveCnt + 1);
                return;
            }

            // 벽이면 제자리로 두고 다음 진행
            if (board[y1Next][x1Next] == '#') {
                x1Next = x1;
                y1Next = y1;
            }

            if (board[y2Next][x2Next] == '#') {
                x2Next = x2;
                y2Next = y2;
            }

            backTracking(board, n, m, x1Next, y1Next, x2Next, y2Next, moveCnt+1);
        }
    }

    public static void main(String[] args) {
        // Test code
        char[][] board = {{'.', '#'}, {'.', '#'}, {'.', '#'}, {'o', '#'}, {'o', '#'}, {'#', '#'}};
        solution(board);

        board = new char[][] {{'#', '#', '#'}, {'.', 'o', '.'}, {'#', '.', '#'}, {'.', 'o', '.'}, {'#', '#', '#'}};
        solution(board);

        board = new char[][] {{'#', '#', '#'}, {'.', 'o', '.'}, {'#', '#', '#'}, {'.', 'o', '.'}, {'#', '#', '#'}};
        solution(board);
    }
}
