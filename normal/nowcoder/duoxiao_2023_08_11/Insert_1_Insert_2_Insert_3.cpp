#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int read() {
    char ch=' ';
    int ans=0;while(ch<'0' || ch>'9')ch=getchar();
    while(ch<='9' && ch>='0'){ans=ans*10+ch-'0';ch=getchar();}
    return ans;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n;
    srand(time(0));
    while (cin >> n) {
        vector<int> a(n + 1, 0), b;
        for (int i = 1; i <= n / 2; i++) a[i] = 1;
        for (int i = n / 2 + 1; i <= n; i++) a[i] = a[i - 1] + 1;
        for (int i = 1; i <= n; i++) {
            // cin >> a[i];
            if (a[i] == 1) b.push_back(i);
        }
        int m = b.size();
        vector<int> R(n + 1, -1);
        vector<vector<int>> q(n + 1);

        LL ans = 0, tmp = 0;
        for (int j = m - 1; j >= 0; j--) {
            int p = b[j];
            q[p].push_back(1), R[p] = p;
            for (int i = p + 1; i <= n; i++) {
                if (R[i] == -1) {
                    if (a[i] == 1) q[p][a[i] - 1]++;
                    else {
                        if (a[i] > q[p].size() + 1) break;
                        if (a[i] == q[p].size() + 1) q[p].push_back(1);
                        else {
                            int l = q[p][a[i] - 2], r = q[p][a[i] - 1];
                            if (r + 1 > l) break;
                            else q[p][a[i] - 1]++;
                        }
                    }
                    R[p] = i;
                } else {
                    while (q[p].size() < q[i].size()) q[p].push_back(0);
                    for (int k = 0; k < q[i].size(); k++) q[p][k] += q[i][k];
                    R[p] = R[i];
                    i = R[i];
                    R[i] = -1;
                    q[i].clear();
                }
            }
            ans += R[p] - p + 1;
            tmp += q[p].size();
            if (tmp >= 200000000) while(1);
            cout << "p= " << p << ' ' << R[p] << '\n';
        }
        cout << ans << " " << tmp << '\n';
    }
    return 0;
}