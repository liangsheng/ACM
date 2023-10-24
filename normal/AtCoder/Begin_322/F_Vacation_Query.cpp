#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int n;
    string S;
    vector<int> b;
    vector<int> a0, L0, R0, a1, L1, R1;

    void init(int N, string str) {
        n = N, S = str;
        b = vector<int>(n << 2, 0);
        a0 = vector<int>(n << 2, 0);
        L0 = vector<int>(n << 2, 0);
        R0 = vector<int>(n << 2, 0);
        a1 = vector<int>(n << 2, 0);
        L1 = vector<int>(n << 2, 0);
        R1 = vector<int>(n << 2, 0);
        build(1, 1, n);
    }

    void push_up(int k, int s, int t) {
        int mid = (s + t) >> 1, l = k << 1, r = l + 1;
        a0[k] = max(a0[l], a0[r]), a0[k] = max(a0[k], R0[l] + L0[r]);
        if (L0[l] == mid - s + 1) L0[k] = L0[l] + L0[r];
        else L0[k] = L0[l];
        if (R0[r] == t - mid) R0[k] = R0[r] + R0[l];
        else R0[k] = R0[r];
        a1[k] = max(a1[l], a1[r]), a1[k] = max(a1[k], R1[l] + L1[r]);
        if (L1[l] == mid - s + 1) L1[k] = L1[l] + L1[r];
        else L1[k] = L1[l];
        if (R1[r] == t - mid) R1[k] = R1[r] + R1[l];
        else R1[k] = R1[r];
    }

    void build(int k, int s, int t) {
        if (s == t) {
            a0[k] = (S[s - 1] == '0');
            L0[k] = a0[k], R0[k] = a0[k];
            a1[k] = (S[s - 1] == '1');
            L1[k] = a1[k], R1[k] = a1[k];
            return ;
        }
        int mid = (s + t) >> 1;
        build(k << 1, s, mid);
        build(k << 1 | 1, mid + 1, t);
        push_up(k, s, t);
    }

    void push_down(int k, int s, int t) {
        if (b[k] == 0) return ;
        int l = k << 1, r = l + 1;
        swap(a0[l], a1[l]), swap(a0[r], a1[r]);
        swap(L0[l], L1[l]), swap(L0[r], L1[r]);
        swap(R0[l], R1[l]), swap(R0[r], R1[r]);
        b[k] = 0, b[l] ^= 1, b[r] ^= 1;
    }

    void update(int k, int s, int t, int l, int r) {
        if (t < l || s > r) return ;
        if (s >= l && t <= r) {
            swap(a0[k], a1[k]);
            swap(L0[k], L1[k]);
            swap(R0[k], R1[k]);
            b[k] ^= 1;
            return ;
        }
        push_down(k, s, t);
        int mid = (s + t) >> 1;
        update(k << 1, s, mid, l, r);
        update(k << 1 | 1, mid + 1, t, l, r);
        push_up(k, s, t);
    }

    int query(int k, int s, int t, int l, int r) {
        // cout << "Hello World" << '\n';
        if (t < l || s > r) return 0;
        if (s >= l && t <= r) return a1[k];
        push_down(k, s, t);
        int mid = (s + t) >> 1;
        int ans = max(query(k << 1, s, mid, l, r), query(k << 1 | 1, mid + 1, t, l, r));
        // 还有可能是左右两边相加得到最大
        ans = max(ans, min(R1[k << 1], mid - l + 1) + min(L1[k << 1 | 1], r - mid));
        return ans;
    }
} seg;

void pr(int k) {
    cout << seg.a0[k] << ' ' << seg.L0[k] << ' ' << seg.R0[k] << '\n';
    cout << seg.a1[k] << ' ' << seg.L1[k] << ' ' << seg.R1[k] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q, c, l, r;
    string s;
    while (cin >> n >> q >> s) {
        seg.init(n, s);
        // pr(3);
        while (q--) {
            cin >> c >> l >> r;
            if (c == 1) {
                seg.update(1, 1, n, l, r);
                // pr(3);
            }
            else cout << seg.query(1, 1, n, l, r) << '\n';
        }
    }
    return 0;
}