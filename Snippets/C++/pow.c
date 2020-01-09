// 二分法
long pow(int a, int n) {
    if (n == 0)
        return 1;
    if (n == 1 || a == 0 || a == 1)
        return a;
    long t = pow(a, n / 2);
    if (n % 2 == 0)
        return t * t;
    else
        return a * t * t;
}

// 三分法
long pow(int a, int n) {
    if (n == 0)
        return 1;
    if (n == 1 || a == 0 || a == 1)
        return a;
    long t = pow(a, n / 3);
    if (n % 3 == 0)
        return t * t * t;
    else if (n % 3 == 1)
        return a * t * t * t;
    else
        return a * a * t * t * t;
}
