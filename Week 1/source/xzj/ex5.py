def binom(n, m, p = 0):
    if(m > n or m < 0):
       return 0;
    if(n < 2):
        return 1;
    if(p == 0):
        p = 1;
        while(p * 2 < n):
            p = p * 2;
    else:
        while(p >= n):
            p = p / 2;
    return binom(n - p, m - p, p) ^ binom(n - p, m, p);
