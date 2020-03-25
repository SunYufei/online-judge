package Search;

class Solution {
    char[][] board;
    char[] words;

    public boolean exist(char[][] board, String word) {
        this.board = board;
        this.words = word.toCharArray();
        for (int i = 0; i < board.length; i++)
            for (int j = 0; j < board[0].length; j++)
                if (dfs(i, j, 0))
                    return true;
        return false;
    }

    boolean dfs(int x, int y, int level) {
        if (x < 0 || x >= board.length || y < 0 || y >= board[0].length || board[x][y] != words[level])
            return false;
        if (level == words.length - 1)
            return true;
        char t = board[x][y];
        board[x][y] = '*';
        boolean res = dfs(x + 1, y, level + 1) || dfs(x - 1, y, level + 1) || dfs(x, y + 1, level + 1)
                || dfs(x, y - 1, level + 1);
        board[x][y] = t;
        return res;
    }
}