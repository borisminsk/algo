int C(int n, int k) { //very slow
    if (n < k) return 0;
    if (n == k) {
        return 1;
    }
    if (n == 0 || k == 0) {
        return 1;
    }
    return C(n - 1, k - 1) + C(n - 1, k);
}
