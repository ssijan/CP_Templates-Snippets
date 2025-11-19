const int mod = 1e9 + 7;

ll modpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

struct Combinatorics {
    vector<ll> fact, invfact;

    Combinatorics(int n) {
        fact.resize(n + 1);
        invfact.resize(n + 1);

        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % mod;
        }

        invfact[n] = modpow(fact[n], mod - 2);
        for (int i = n - 1; i >= 0; i--) {
            invfact[i] = invfact[i + 1] * (i + 1) % mod;
        }
    }

    ll nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return ((fact[n] * invfact[r] % mod) * invfact[n - r]) % mod;
    }
};
// Combinatorics cmb(n);
