const int k = 500;

class matrix {
public:
    vector<bitset<k>> m;


    void clear() {
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                m[i][j] = 0;
            }
        }
    }

    matrix() {
        m.assign(k, bitset<k>());
        clear();
    }

    matrix(const vector<bitset<k>>& an) {
        m = an;
    }


    const auto& operator[](int t) const {
        return m[t];
    }


    matrix operator*(const vector <bitset<k>>& an) const {
        vector <bitset<k>> result(k, bitset<k>());
        for(int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                if ((m[i] & an[j]).any()) {
                    result[i][j] = 1;
                } else {
                    result[i][j] = 0;
                }
            }
        }
        return matrix(result);
    }

    matrix trans() const {
        vector <bitset<k>> result(k, bitset<k>());
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                result[i][j] = m[j][i];
            }
        }
        return matrix(result);
    }

    matrix operator*(const matrix& an) const {
        return *this * an.trans().m;
    }
};


/*
matrix binpow(matrix a, ll n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        return binpow(a*a, n/2);
    } else {
        return (binpow(a, n - 1) * a);
    }
}
*/
