#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 2222222
#define N 222222
#define C 333

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

pair<pt, int> q[N];
long long ans[N];
int a[N], b[N];
int cnt[M];

bool cmp(pair<pt, int> a, pair<pt, int> b) {
    if (a.F.F / C != b.F.F / C) return a.F.F / C < b.F.F / C;
    return a.F.S < b.F.S;
}

int main(){
//  freopen(TASK".in","r",stdin);
//  freopen(TASK".out","w",stdout);
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    b[0] = 0;
    for (int i = 1; i <= n; i++) b[i] = b[i - 1] ^ a[i - 1];
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &q[i].F.F, &q[i].F.S);
        --q[i].F.F;
        q[i].S = i;
    }
    sort(q, q + m, cmp);
    int l = 0;
    int r = -1;
    long long cur = 0;
    for (int i = 0; i < m; i++) {
        while (r < q[i].F.S) {
            cur += cnt[b[++r] ^ k];
            cnt[b[r]]++;
        }
        while (l > q[i].F.F) {
            cur += cnt[b[--l] ^ k];
            cnt[b[l]]++;
        }
        while (r > q[i].F.S) {
            cnt[b[r]]--;
            cur -= cnt[b[r--] ^ k];
        }
        while (l < q[i].F.F) {
            cnt[b[l]]--;
            cur -= cnt[b[l++] ^ k];
        }
        for (int h = 0; h < 10; h++) cout << "h= " << h << " = " << cnt[h] << '\n';
        cout << "cur= " << cur << '\n';
        ans[q[i].S] = cur;
    }
    for (int i = 0; i < m; i++) printf("%lld\n", ans[i]);
}
