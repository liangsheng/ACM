#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int N = 500005;

inline int read() { 
    int x=0,w=0; char ch=0; while(!isdigit(ch)) w|=ch=='-',ch=getchar();
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar(); return w?-x:x; 
}

int L, n, m;
int a[N];

bool ok(int mid) {
    int now = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] - now > mid) return false;
        while (i + 1 < n && a[i + 1] - now <= mid) i++;
        cnt++, now = a[i];
    }
    return cnt <= m;
};

int main() {
    while (~scanf("%d %d %d", &L, &n, &m)) {
        
        for (int i = 0; i < n; i++) a[i] = read();
        a[n++] = L;
        sort(a, a + n);

        // for (int i = 1; i <= l; i++) cout << i << ' ' << ok(i) << '\n';
        int l = 1, r = L, mid;
        while (l != r) {
            mid = (l + r) / 2;
            // cout << "l= " << l << ", r= " << r << ", mid= " << mid << " " << ok(mid) << '\n';
            if (ok(mid)) r = mid;
            else l = mid + 1;
        }
        printf("%d\n", l);
    }
    return 0;
}