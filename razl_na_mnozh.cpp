vector<pair<ll,ll>> razl(ll b) {
    vector <pair<ll, ll>> res;
    ll s = sqrt(b) + 5;
    s = min(s, b);
    for (ll i = 2; i < s; ++i) {
        if (b % i == 0) {
            pair<ll, ll> next = {i, 0};
            while(b % i == 0) {
                b /= i;
                ++next.second;
            }
            res.eb(move(next));
        }
    }
    if (b > 1) res.eb(b, 1);
    return res;
}
