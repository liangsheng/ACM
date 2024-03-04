#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 100005;
 
vector<LL> a;
    
void build(int k, int s, int t, vector<LL>& A) {
    if (s == t) {
        a[k] = A[s];
        return ;
    }    
    int mid = (s + t) >> 1;
    build(k << 1, s, mid, A);
    build(k << 1 | 1, mid + 1, t, A);
    a[k] = a[k << 1] + a[k << 1 | 1];
}
    
void update(int k, int s, int t, int l, int r) {
    if (t < l || s > r) return ;
    if (s >= l && t <= r) {
        if (a[k] == t - s + 1) return ;
        if (s == t) {
            a[k] = sqrt(a[k]);
            return ;
        }
    }
    int mid = (s + t) >> 1;
    update(k << 1, s, mid, l, r);
    update(k << 1 | 1, mid + 1, t, l, r);
    a[k] = a[k << 1] + a[k << 1 | 1];
}
    
LL query(int k, int s, int t, int l, int r) {
    if (s > r || t < l) return 0;
    if (s >= l && t <= r) return a[k];
    int mid = (s + t) >> 1;
    LL ans = query(k << 1, s, mid, l, r);
    ans += query(k << 1 | 1, mid + 1, t, l, r);
    return ans;
}
    
void init(int n, vector<LL>& A) {
    a = vector<LL>(n * 4, 0);
    build(1, 1, n, A);
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int n, m, c, l, r;
    cin >> n;
    vector<LL> A(n + 1);
    for (int i = 1; i <= n; i++) cin >> A[i];
    init(n, A);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> c >> l >> r;
        if (l > r) swap(l, r);
        if (c == 1) cout << query(1, 1, n, l, r) << '\n';
        else update(1, 1, n, l, r);
    }
    return 0;
}
