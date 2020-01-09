#include <cmath>

bool IsPrime(int m) {
    if (m <= 1)
        return false;
    for (int i = 2; i <= (int)sqrt(m); i++)
        if (m % i == 0)
            return false;
    return true;
}
