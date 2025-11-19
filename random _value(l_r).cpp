mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
// rnd() -> generates a random number
 
int rndRange(int l, int r) { return rnd() % (r - l + 1) + l; }
// int i = rndRange(l, r); return random value between l to r
