const int N = 1e6 + 5;
int spf[N]; 
void build_spf() {
    for (int i = 2; i < N; i++) {
        if (spf[i] == 0) {          
            for (int j = i; j < N; j += i) {
                if (spf[j] == 0)
                    spf[j] = i;
            }
        }
    }
}
