def C(n, k)
    if (n == 0 && k == 0) return 1;
    if (n < k) return 0;
    if (k < 0) return 0;
    return C(n - 1, k) + C(n - 1, k - 1);
    