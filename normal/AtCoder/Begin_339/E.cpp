#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
const int INF = numeric_limits<int>::max() / 2;

/*-------------------------- 线段树 begin ----------------*/
int a[N << 2];

// 初始化线段树
void init(int k, int s, int t) {
    if (s == t) {
        a[k] = 0;  // 这里可以写自己的初始化逻辑
        return ;
    }
    int mid = (s + t) >> 1;
    init(k << 1, s, mid);
    init(k << 1 | 1, mid + 1, t);
    // 这里可以写自己的初始化逻辑, 这里是求较大值
    a[k] = max(a[k << 1], a[k << 1 | 1]);
}

// 单点更新
void update(int k, int s, int t, int x, int val) {
    if (x < s || x > t) return;
    if (s == t) {
        a[k] = max(a[k], val);
        return;
    }
    int mid = (s + t) >> 1;
    if (x <= mid) update(k << 1, s, mid, x, val);
    else update(k << 1 | 1, mid + 1, t, x, val);
    a[k] = max(a[k << 1], a[k << 1 | 1]);
}

// 区间查询
int query(int k, int s, int t, int l, int r) {
    if (s > r || t < l) return -INF;
    if (s >= l && t <= r) return a[k];
    int mid = (s + t) >> 1;
    int ans = query(k << 1, s, mid, l, r);
    ans = max(ans, query(k << 1 | 1, mid + 1, t, l, r));
    return ans;
}
/*-------------------------- 线段树 end ------------------*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d, e;
    cin >> n >> d;
    vector<int> a(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i], c[i] = a[i];
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    e = c.size();
    init(1, 1, e);
    
    // printf("e= %d\n", e);
    // for (int x : c) printf("%d ", x);
    // puts("");
    int ans = 1;
    for (int i = 0; i < n; i++) {
        int l = lower_bound(c.begin(), c.end(), a[i] - d) - c.begin();
        int r = upper_bound(c.begin(), c.end(), a[i] + d) - c.begin() - 1; 
        int tmp = query(1, 1, e, l + 1, r + 1);
        ans = max(ans, tmp + 1);
        int id = lower_bound(c.begin(), c.end(), a[i]) - c.begin();
        update(1, 1, e, id + 1, tmp + 1);
        // printf("i= %d, l= %d, r= %d, tmp= %d\n", i, l, r, tmp);
    }
    cout << ans << '\n';
    return 0;
}