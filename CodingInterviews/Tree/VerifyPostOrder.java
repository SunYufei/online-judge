package Tree;

class Solution {
    public boolean verifyPostorder(int[] postorder) {
        if (postorder == null || postorder.length <= 2)
            return true;
        return check(0, postorder.length - 1, postorder);
    }

    boolean check(int l, int r, int[] order) {
        if (l >= r)
            return true;
        int i;
        for (i = l; i < r; i++)
            if (order[i] > order[r])
                break;
        for (int j = i; j < r; j++)
            if (order[j] < order[r])
                return false;
        return check(l, i - 1, order) && check(i, r - 1, order);
    }
}