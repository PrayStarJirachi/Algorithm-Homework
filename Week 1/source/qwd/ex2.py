dp={}
def C(n, k) :
    if (n == k or k == 0) :
        return 1
    if (dp.has_key((n, k))) :
        return dp[(n, k)]
    dp[(n, k)] = C(n - 1, k - 1) + C(n - 1, k)
    return dp[(n, k)]
