#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 2e9;
const ll base = 998244353;
const int maxn = 100500;

vector <ll> p;

ll solve(int n) { //presentation of n. Must be call for smaller n.
    if (n == 0) return 1;
    ll q = 1;
    ll z = 1;
    ll sum = 0;
    while ((3*q*q - q)/2 <= n) {
        sum += z*p[n - (3*q*q - q)/2];
        if (sum >= base) sum -=base;
        if (sum < 0) sum +=base;
        if ((3*q*q + q)/2 <= n) {
            sum += z*p[n - (3*q*q + q)/2];
            if (sum >= base) sum -=base;
            if (sum < 0) sum +=base;
        }
        ++q;
        z*=-1;
    }
    return sum;
}


int main() {
    //freopen("input.txt", "r", stdin);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; cin >> n;
    p.assign(n + 5, 1);
    for (int i = 2; i <= n; ++i) {
        p[i] = solve(i);
    }
    cout << solve(n + 1) - 1;
    return 0;
}
