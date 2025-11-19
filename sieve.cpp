vector<int> prm;
vector<bool> is_prime;

void sieve(int n) {
    is_prime.assign(n + 1, true);
    prm.clear();
    
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i])
            prm.push_back(i);
        
        for (auto p : prm) {
            if (p * i > n) break;
            is_prime[p * i] = false;
            if (i % p == 0) break;
        }
    }

}
