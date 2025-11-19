const int N = 2e5 + 5;
int a[N];

// -- Segment Tree --
struct Node {
    long long sum;
    pair<int, int> mn;
    pair<int, int> mx;
};

Node tr[4 * N];

Node merge(const Node& left, const Node& right) {
    Node res;
    res.sum = left.sum + right.sum;

    // Min
    if (left.mn.first < right.mn.first)
        res.mn = left.mn;
    else if (left.mn.first > right.mn.first)
        res.mn = right.mn;
    else
        res.mn = min(left.mn, right.mn);

    // Max
    if (left.mx.first > right.mx.first)
        res.mx = left.mx;
    else if (left.mx.first < right.mx.first)
        res.mx = right.mx;
    else
        res.mx = min(left.mx, right.mx);

    return res;
}

//Build_ST(0, 0, n - 1);
void Build_ST(int node, int st, int en) {
    if (st == en) {
        tr[node] = {
            a[st],
            {a[st], st},
            {a[st], st}
        };
        return;
    }
    int mid = (st + en) / 2;
    Build_ST(2 * node + 1, st, mid);
    Build_ST(2 * node + 2, mid + 1, en);
    tr[node] = merge(tr[2 * node + 1], tr[2 * node + 2]);
}

// update(0, 0, n - 1, pos, new_val);
void update(int node, int st, int en, int pos, int new_val) {
    if (st == en) {
        a[pos] = new_val;
        tr[node] = {
            new_val,
            {new_val, pos},
            {new_val, pos}
        };
        return;
    }
    int mid = (st + en) / 2;
    if (pos <= mid)
        update(2 * node + 1, st, mid, pos, new_val);
    else
        update(2 * node + 2, mid + 1, en, pos, new_val);

    tr[node] = merge(tr[2 * node + 1], tr[2 * node + 2]);
}

// query(0, 0, n - 1, l, r)
Node query(int node, int st, int en, int l, int r) {
    if (r < st || en < l) return {0, {INT_MAX, -1}, {INT_MIN, -1}};
    if (l <= st && en <= r) return tr[node];

    int mid = (st + en) / 2;
    Node left = query(2 * node + 1, st, mid, l, r);
    Node right = query(2 * node + 2, mid + 1, en, l, r);
    return merge(left, right);
}

