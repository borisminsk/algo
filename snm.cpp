const int maxn = 100500;
int parent[maxn];
int rankk[maxn];

void make_set (int v) {
    parent[v] = v;
    rankk[v] = 0;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rankk[a] < rankk[b])
            swap (a, b);
        parent[b] = a;
        if (rankk[a] == rankk[b])
            ++rankk[a];
    }
}
