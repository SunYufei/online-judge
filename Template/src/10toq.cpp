void ten_to_q(int y, int q) {
    int z[40], num = 0;
    do {
        z[num++] = y % q;
        y /= q;
    } while (y != 0);
    for (int i = num - 1; i >= 0; --i)
        printf("%d", z[i]);
}