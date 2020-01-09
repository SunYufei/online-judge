int p_to_ten(int x, int p) {
    int y = 0, tmp = 1;
    while (x != 0) {
        y = y + (x % 10) * tmp;
        x /= 10;
        tmp *= p;
    }
    return y;
}