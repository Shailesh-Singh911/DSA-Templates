class SegTree {
public:
    vector <pair<int, int>> tree;

    SegTree(int n) {
        tree.resize(n * 4, {INF, 0});
    }

    pair<int, int> func(pair<int, int> a, pair<int, int> b) {
        if(a.first < b.first) return a;
        return b;
    }

    void update(int node, int start, int end, int pos, int val) {
        if(start == end) {
            tree[node] = {val, start};
        } else {
            int mid = (start + end)/2;
            if(pos <= mid) {
                update(node*2, start, mid, pos, val);
            } else {
                update(node*2 + 1, mid + 1, end, pos, val);
            }
            tree[node] = func(tree[node*2], tree[node*2 + 1]);
        }
    }

    pair<int, int> query(int node, int start, int end, int l, int r) {
        if(l > r) {
            return {INF, 0};
        }
        if(l == start && r == end) {
            return tree[node];
        }
        int mid = (start + end)/2;
        return func(query(node*2, start, mid, l, min(mid, r)), query(node*2 + 1, mid + 1, end, max(l, mid + 1), r));
    }
};
