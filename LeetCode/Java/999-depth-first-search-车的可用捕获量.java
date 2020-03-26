/*
 * @lc app=leetcode.cn id=999 lang=java
 *
 * [999] 车的可用捕获量
 */

// @lc code=start
class Solution {
    public int numRookCaptures(char[][] board) {
        int res = 0;
        int x = -1, y = -1;
        int[] dx = new int[] { 0, 1, 0, -1 };
        int[] dy = new int[] { 1, 0, -1, 0 };
        for (int i = 0; i < 8 && x == -1; i++)
            for (int j = 0; j < 8; j++)
                if (board[i][j] == 'R') {
                    x = i;
                    y = j;
                    break;
                }
        for (int i = 0; i < 4; i++)
            for (int step = 0;; step++) {
                int nx = x + step * dx[i];
                int ny = y + step * dy[i];
                if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8 || board[nx][ny] == 'B')
                    break;
                if (board[nx][ny] == 'p') {
                    ++res;
                    break;
                }
            }
        return res;
    }
}
// @lc code=end
