const int mod1 = 1e9 + 7, mod2 = 1e9 + 9;
const int base1 = 137, base2 = 139;
const int N = 1e6+5;
array<int, 2> pw[N], invpw[N], pref[N];
int invp(int a, int b, int MOD)
{
    int tot = 1;

    while (b)
    {
        if (b & 1)
        {
            tot = 1LL * tot * a % MOD;
        }
        a = 1LL * a * a % MOD;
        b >>= 1;
    }

    return tot;
}
void pre()
{
    pw[0][0] = 1;
    pw[0][1] = 1;
    invpw[0][0] = 1;
    invpw[0][1] = 1;
                                        
    int inv1 = invp(base1, mod1 - 2, mod1);
    int inv2 = invp(base2, mod2 - 2, mod2);

    for (int i = 1; i < N; ++i)
    {
        pw[i][0] = 1LL * pw[i - 1][0] * base1 % mod1;
        pw[i][1] = 1LL * pw[i - 1][1] * base2 % mod2;

        invpw[i][0] = 1LL * invpw[i - 1][0] * inv1 % mod1;
        invpw[i][1] = 1LL * invpw[i - 1][1] * inv2 % mod2;
    }
}

void SH(string &s)
{
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        if (i)
        {
            pref[i][0] = (pref[i - 1][0] + (1LL * s[i] * pw[i][0] % mod1)) % mod1;
            pref[i][1] = (pref[i - 1][1] + (1LL * s[i] * pw[i][1] % mod2)) % mod2;
        }
        else
        {
            pref[i][0] = ((1LL * s[i] * pw[i][0] % mod1)) % mod1;
            pref[i][1] = ((1LL * s[i] * pw[i][1] % mod2)) % mod2;
        }
    }
}

ll get_str(int l, int r)
{
    assert(l <= r);
    array<int, 2> hs{0, 0};
    hs[0] = pref[r][0];
    if (l)
        hs[0] = (hs[0] - pref[l - 1][0] + mod1) % mod1;
    hs[0] = 1LL * hs[0] * invpw[l][0] % mod1;
    hs[0] %= mod1;
    hs[1] = pref[r][1];
    if (l)
        hs[1] = (hs[1] - pref[l - 1][1] + mod2) % mod2;
    hs[1] = 1LL * hs[1] * invpw[l][1] % mod2;
    hs[1] %= mod2;
    return ((ll)hs[0] << 31) | hs[1];
}
