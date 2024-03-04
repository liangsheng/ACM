#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
    
const int N = 1000005;
 
inline int read() { 
    int x=0,w=0; char ch=0; while(!isdigit(ch)) w|=ch=='-',ch=getchar();
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar(); return w?-x:x; 
}
 
vector<LL> a, b;
    
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
    
void push_down(int k, int s, int t) {
    if (b[k] == 0) return ;
    int l = k << 1, r = l + 1, mid = (s + t) >> 1;
    a[l] += (mid - s + 1) * b[k], b[l] += b[k];
    a[r] += (t - mid) * b[k], b[r] += b[k];
    b[k] = 0;
        
}
    
void update(int k, int s, int t, int l, int r, LL val) {
    if (t < l || s > r) return ;
    if (s >= l && t <= r) {
        a[k] += (t - s + 1) * val;
        b[k] += val;
        return ;
    }
    push_down(k, s, t);
    int mid = (s + t) >> 1;
    update(k << 1, s, mid, l, r, val);
    update(k << 1 | 1, mid + 1, t, l, r, val);
    a[k] = a[k << 1] + a[k << 1 | 1];
}
    
LL query(int k, int s, int t, int l, int r) {
    if (s > r || t < l) return 0;
    if (s >= l && t <= r) return a[k];
    push_down(k, s, t);
    int mid = (s + t) >> 1;
    LL ans = query(k << 1, s, mid, l, r);
    ans += query(k << 1 | 1, mid + 1, t, l, r);
    return ans;
}
    
void init(int n, vector<LL>& A) {
    a = vector<LL>(n * 4, 0);
    b = vector<LL>(n * 4, 0);
    build(1, 1, n, A);
}
    
    
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int n, m, c, l, r;
    LL val;
    // while (cin >> n >> m) {
    n = read(), m = read();
        vector<LL> A(n + 1);
        for (int i = 1; i <= n; i++) A[i] = read();
        init(n, A);
        for (int i = 1; i <= m; i++) {
            // cin >> c >> l >> r;
            c = read();
            l = read();
            r = read();
            if (c == 2) cout << query(1, 1, n, l, r) << '\n';
            else {
                // cin >> val;
                val = read();
                update(1, 1, n, l, r, val);
            }
        }
    // }
    return 0;
}

