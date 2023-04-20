#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pii;

inline LL read() { 
    LL x=0,w=0; char ch=0; while(!isdigit(ch)) w|=ch=='-',ch=getchar(); //while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();以前以为位运算能快点，但问了大佬才发现，其实没啥差别 
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar(); return w?-x:x; 
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    LL n, m, k;
    while (cin >> n >> m >> k) {
        // n = read(), m = read(), k = read();
        vector<LL> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        set<pii> sk, so;
        LL now = 0;
        vector<LL> ans;
        for (int i = 1; i < m; i++) {
            sk.insert({a[i], i});
            now += a[i];
            if (sk.size() > k) {
                auto it = sk.end();
                it--;
                so.insert(*it);
                now -= it->X;
                sk.erase(it);
            }
        }
        for (int i = m; i <= n; i++) {
            sk.insert({a[i], i});
            now += a[i];
            if (sk.size() > k) {
                auto it = sk.end();
                it--;
                so.insert(*it);
                now -= it->X;
                sk.erase(it);
            }
            ans.push_back(now);

            pii t = {a[i - m + 1], i - m + 1};
            if (so.count(t)) so.erase(t);
            else {
                sk.erase(t);
                now -= a[i - m + 1];
                if (!so.empty()) {
                    auto it = so.begin();
                    now += it->X;
                    sk.insert(*it);
                    so.erase(it);
                }
            }
        }
        for (int i = 0; i < ans.size() - 1; i++) cout << ans[i] << " ";
        cout << ans[ans.size() - 1] << "\n";
    }
    return 0;
}