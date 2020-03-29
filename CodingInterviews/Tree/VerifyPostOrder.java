package Tree;

class Solution {
    public boolean verifyPostorder(int[] postorder) {
        if (postorder == null || postorder.length == 0)
            return true;
        return check(0, postorder.length - 1, postorder);
    }

    boolean check(int l, int r, int[] order) {

    }
}