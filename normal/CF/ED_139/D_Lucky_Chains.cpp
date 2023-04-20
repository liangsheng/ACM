#include <bits/stdc++.h>
using namespace std;

inline int read() { 
    int x=0,w=0; char ch=0; while(!isdigit(ch)) w|=ch=='-',ch=getchar(); //while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();以前以为位运算能快点，但问了大佬才发现，其实没啥差别 
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar(); return w?-x:x; 
}

int T, x, y, ans;
vector<int> g, h;

void gao(int p, int now) {
    if (p == g.size()) {
        if (now == 1) return ;
        // cout << "now= " << now << ", ans= " << ans << '\n';
        ans = min(ans, now - x % now);
        return ;
    }
    gao(p + 1, now);
    for (int i = 0; i < h[p]; i++) {
        now *= g[p];
        gao(p + 1, now);
    }
}

int main() {
    int N = 10000000;
    vector<bool> f(N + 1, 0);
    vector<int> p;
    for (int i = 2; i <= N; i++) {
        if (f[i]) continue;
        p.push_back(i);
        for (long long j = (long long) i * i; j <= N; j += i) f[j] = 1;
    }
    ios::sync_with_stdio(false);
    cin.tie(0);
    T = read();
    while (T--) {
        x = read();
        y = read();
        int d = __gcd(x, y);
        if (d > 1) cout << 0 << '\n';
        else {
            int a = y - x;
            if (a == 1) cout << -1 << '\n';
            else {
                ans = a - x % a;
                g.clear(), h.clear();
                for (int i = 0; i < p.size() && (long long) p[i] * p[i] <= a; i++) {
                    if (a % p[i]) continue;
                    int e = 0;
                    while (a % p[i] == 0) e++, a /= p[i];
                    g.push_back(p[i]);
                    h.push_back(e);
                }
                if (a != 1) g.push_back(a), h.push_back(1);
                gao(0, 1);
                // for (int i = 0; i < g.size(); i++) cout << "hh " << g[i] << ' ' << h[i] << '\n';
                cout << ans << '\n';
            }
        }
    }
    return 0;
}