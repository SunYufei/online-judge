#include "main.h"

class Solution {
  public:
    bool verifyPostorder(vector<int> &postorder) {
        if (postorder.empty())
            return false;
        return check(postorder, 0, postorder.size() - 1);
    }

  private:
    bool check(vector<int> &post, int left, int right) {
        if (left >= right)
            return true;
        int root = post[right];
        int k = left;
        while (k < right && post[k] < root)
            ++k;
        for (int i = k; i < right; i++)
            if (post[i] < root)
                return false;
        return check(post, left, k - 1) && check(post, k, right - 1);
    }
};