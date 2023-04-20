#include <bits/stdc++.h>
using namespace std;

inline int read() { 
    int x=0,w=0; char ch=0; while(!isdigit(ch)) w|=ch=='-',ch=getchar();
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar(); return w?-x:x; 
}

const int N = 10000000;

vector<int> mp(N + 1, 0);
vector<int> p;

// jingly code
// https://codeforces.com/contest/1766/submission/184952734
void init() {
    for (int i = 2; i <= N; i++) {
        if (mp[i] == 0) mp[i] = i, p.push_back(i);
        for (int t : p) {
            if (i * t > N) break;
            mp[i * t] = t;
            if (i % t == 0) break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int T, x, y;
    T = read();
    while (T--) {
        x = read();
        y = read();
        int a = y - x;
        if (a == 1) cout << -1 << '\n';
        else {
            int ans = 1e9;
            while (a != 1) {
                ans = min(ans, (mp[a] - x % mp[a]) % mp[a]);
                a /= mp[a];
            }
            cout << ans << '\n';
        }
    }
    return 0;
}