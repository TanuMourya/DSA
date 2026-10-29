
class Solution {
    vector<vector<int>> adj;
    vector<int> parent, depth, sz, heavy;
    vector<int> head, pos;
    vector<int> seg;
    int timer = 0;

    int dfs(int u, int p) {
        parent[u] = p;
        sz[u] = 1;
        int largest = 0;

        for (int v : adj[u]) {
            if (v == p) continue;

            depth[v] = depth[u] + 1;
            int sub = dfs(v, u);
            sz[u] += sub;

            if (sub > largest) {
                largest = sub;
                heavy[u] = v;
            }
        }

        return sz[u];
    }

    void decompose(int u, int h, string& s,
                   vector<int>& base) {
        head[u] = h;
        pos[u] = timer;
        base[timer++] = 1 << (s[u] - 'a');

        if (heavy[u] != -1) {
            decompose(heavy[u], h, s, base);
        }

        for (int v : adj[u]) {
            if (v == parent[u] || v == heavy[u]) continue;
            decompose(v, v, s, base);
        }
    }

    void build(int node, int l, int r,
               vector<int>& base) {
        if (l == r) {
            seg[node] = base[l];
            return;
        }

        int mid = (l + r) / 2;
        build(node * 2, l, mid, base);
        build(node * 2 + 1, mid + 1, r, base);

        seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
    }

    void update(int node, int l, int r,
                int idx, int val) {
        if (l == r) {
            seg[node] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);

        seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
    }

    int query(int node, int l, int r,
              int ql, int qr) {
        if (ql <= l && r <= qr) return seg[node];

        int mid = (l + r) / 2;
        int ans = 0;

        if (ql <= mid)
            ans ^= query(node * 2, l, mid, ql, qr);

        if (qr > mid)
            ans ^= query(node * 2 + 1, mid + 1, r, ql, qr);

        return ans;
    }

    int pathQuery(int u, int v, int n) {
        int mask = 0;

        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]])
                swap(u, v);

            mask ^= query(1, 0, n - 1,
                          pos[head[u]], pos[u]);

            u = parent[head[u]];
        }

        if (depth[u] > depth[v]) swap(u, v);

        mask ^= query(1, 0, n - 1, pos[u], pos[v]);

        return mask;
    }

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        adj.assign(n, {});

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        parent.assign(n, -1);
        depth.assign(n, 0);
        sz.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);

        dfs(0, -1);

        vector<int> base(n);
        timer = 0;
        decompose(0, 0, s, base);

        seg.assign(4 * n, 0);
        build(1, 0, n - 1, base);

        vector<bool> ans;

        for (string& q : queries) {
            stringstream ss(q);
            string type;
            int u, v;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                s[u] = c;
                int mask = 1 << (c - 'a');

                update(1, 0, n - 1, pos[u], mask);
            } else {
                ss >> v;

                int mask = pathQuery(u, v, n);

                ans.push_back(
                    (mask & (mask - 1)) == 0
                );
            }
        }

        return ans;
    }
};
