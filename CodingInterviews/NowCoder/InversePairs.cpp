#include "main.h"

class Solution {
  public:
    int InversePairs(vector<int> data) {
        return mergeSort(data, 0, data.size() - 1);
    }

  private:
    int mergeSort(vector<int> &data, int l, int r) {
        
    }
};