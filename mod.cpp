int add(int a, int b) {
    int res = a + b;
    if (res >= mod) res -= mod;
    return res;
}

int mul(int a, int b) {
    return (1LL * a * b) % mod;
}

int binpow(int a, int n) {
    if (n == 0) return 1;
    else if (n & 1) return mul(a, binpow(a, n - 1));
    else return binpow(mul(a, a), n / 2);
}

int sub(int a, int b) {
    int res = a - b;
    if (res < 0) res += mod;
    return res;
}

int rev(int a) {
    return binpow(a, mod - 2);
}

vector<int> fact;
vector<int> rev_fact;

void calc_fact(int n) {
    fact.assign(n + 1, 0);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = mul(fact[i - 1], i);
    }
    rev_fact.assign(n + 1, 0);
    for (int i = 0; i <= n; ++i) {
        rev_fact[i] = rev(fact[i]);
    }
}

int C(int n, int k) {
    return mul(fact[n], mul(rev_fact[k], rev_fact[n - k]));
}