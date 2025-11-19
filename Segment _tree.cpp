const int N = 2e5 + 5;
int a[N];

// -- Segment tree --
struct Node {
    long long sum;
    int mn, mx;
};

Node tr[4 * N]; 

Node merge(Node left, Node right) {
    return {
        left.sum + right.sum,
        min(left.mn, right.mn),
        max(left.mx, right.mx)
    };
}

//Build_ST(0, 0, n - 1);
void Build_ST(int node, int st, int en) {
    if (st == en) {
        tr[node] = {a[st], a[st], a[st]};
        return;
    }

    int mid = (st + en) / 2;
    Build_ST(2 * node + 1, st, mid);
    Build_ST(2 * node + 2, mid + 1, en);
    tr[node] = merge(tr[2 * node + 1], tr[2 * node + 2]);
}

// query(0, 0, n - 1, l, r);
Node query(int node, int st, int en, int l, int r) {
    if (r < st || en < l) {
        return {0, INT_MAX, INT_MIN}; 
    }
    if (l <= st && en <= r) {
        return tr[node];
    }

    int mid = (st + en) / 2;
    Node left = query(2 * node + 1, st, mid, l, r);
    Node right = query(2 * node + 2, mid + 1, en, l, r);
    return merge(left, right);
}

// update(0, 0, n - 1, pos, new_val);
void update(int node, int st, int en, int pos, int new_val) {
    if (st == en) {
        a[pos] = new_val;
        tr[node] = {new_val, new_val, new_val};
        return;
    }

    int mid = (st + en) / 2;
    if (pos <= mid)
        update(2 * node + 1, st, mid, pos, new_val);
    else
        update(2 * node + 2, mid + 1, en, pos, new_val);
    
    tr[node] = merge(tr[2 * node + 1], tr[2 * node + 2]);
}

