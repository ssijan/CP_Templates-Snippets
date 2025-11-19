int t = 0, l = 0, r = n - 1, b = n - 1, k = n * n - 1;

int ans[n][n];

while (t <= b && l <= r) {
    for (int i = l; i <= r; i++) {
        ans[t][i] = k;
        k--;
    }
    t++;
    for (int i = t; i <= b; i++) {
        ans[i][r] = k--;
    }
    r--;
    if (t <= b) {
        for (int i = r; i >= l; i--) {
            ans[b][i] = k--;
        }
        b--;
    }
    if (l <= r) {
        for (int i = b; i >= t; i--) {
            ans[i][l] = k--;
        }
        l++;
    }
}
