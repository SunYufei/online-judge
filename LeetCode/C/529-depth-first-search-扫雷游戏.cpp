/*
 * @lc app=leetcode.cn id=529 lang=cpp
 *
 * [529] 扫雷游戏
 */
#include "main.h"
// @lc code=start
class Solution {
  public:
    vector<vector<char>> updateBoard(vector<vector<char>> &board,
                                     vector<int> &click) {
        int m = board.size(), n = board[0].size();
        int x = click[0], y = click[1];
        if (board[x][y] == 'M' || board[x][y] == 'X') {
            board[x][y] = 'X';
            return board;
        }

        int num = 0;
        for (auto dir : dirs) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            if (check(nx, ny, m, n) && board[nx][ny] == 'M')
                ++num;
        }
        if (num > 0) {
            board[x][y] = '0' + num;
            return board;
        }

        board[x][y] = 'B';

        for (auto dir : dirs) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            if (check(nx, ny, m, n) && board[nx][ny] == 'E') {
                vector<int> pos = {nx, ny};
                updateBoard(board, pos);
            }
        }

        return board;
    }

  private:
    bool check(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    int dirs[8][2] = {{0, -1}, {0, 1},  {1, 0},  {-1, 0},
                      {1, 1},  {1, -1}, {-1, 1}, {-1, -1}};
};
// @lc code=end
