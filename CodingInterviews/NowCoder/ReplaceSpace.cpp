#include "main.h"

class Solution {
  public:
    void replaceSpace(char *str, int length) {
        for (int i = 0; i < length; i++)
            if (str[i] == ' ') {
                for (int j = length + 2; j > i; --j)
                    str[j] = str[j - 2];
                length += 2;
                str[i] = '%';
                str[i + 1] = '2';
                str[i + 2] = '0';
                i += 2;
            }
    }
};