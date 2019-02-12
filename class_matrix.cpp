int k;

class matrix {
public:
    vector <vector <ll>> m;

    matrix(int s) {
        m.assign(k, vector <ll>(k, 0));
        for(int i = 0; i < k; ++i) {
            m[i][i] = s;
        }
    }

    matrix(const vector <vector <ll>>& an) {
        m = an;
    }

    matrix() {
        m.assign(k, vector <ll>(k, 0));
    }

    matrix(const vector<ll>& b) {
        m.assign(k, vector <ll>(k, 0));
        for (int i = 0; i < k - 1; ++i) {
            m[i][i + 1] = 1;
        }
        for (int i = 0; i < k; ++i) {
            m[k - 1][i] = b[i];
        }
    }

    const auto& operator[](int t) const {
        return m[t];
    }


    matrix operator*(const matrix& an) const {
        vector <vector <ll>> result(k, vector <ll>(k));
        for(int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                for (int l = 0; l < k; ++l) {
                    result[i][j] += m[i][l] * an[l][j];
                    result[i][j] %= base - 1;
                }
            }
        }
        return matrix(result);
    }

    vector <ll> operator*(const vector<ll>& an) const {
        vector <ll> result(k, 0);
        for (int i = 0; i < k; ++i) {
            for (int t = 0; t < k; ++t) {
                result[i] += an[t]*m[i][t];
                result[i] %= base - 1;
            }
        }
        return result;
    }

};



matrix binpow(matrix a, ll n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        return binpow(a*a, n/2);
    } else {
        return (binpow(a, n - 1) * a);
    }
}
