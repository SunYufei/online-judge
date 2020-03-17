/*
 * @lc app=leetcode.cn id=529 lang=java
 *
 * [529] 扫雷游戏
 */

// @lc code=start
class Solution {
    private int[][] dirs = { { 0, -1 }, { 0, 1 }, { 1, 0 }, { -1, 0 }, { 1, 1 }, { 1, -1 }, { -1, 1 }, { -1, -1 } };

    private boolean checkPos(int x, int y, int n, int m) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    public char[][] updateBoard(char[][] board, int[] click) {
        int n = board.length;
        int m = board[0].length;
        int x = click[0];
        int y = click[1];

        if (board[x][y] == 'M' || board[x][y] == 'X') {
            board[x][y] = 'X';
            return board;
        }

        int num = 0;
        for (var dir : dirs) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            if (checkPos(nx, ny, n, m) && board[nx][ny] == 'M')
                ++num;
        }
        if (num > 0) {
            board[x][y] = Character.forDigit(num, 10);
            return board;
        }

        board[x][y] = 'B';

        for (var dir : dirs) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            if (checkPos(nx, ny, n, m) && board[nx][ny] == 'E') {
                int[] next_click = { nx, ny };
                updateBoard(board, next_click);
            }
        }

        return board;
    }
}
// @lc code=end
