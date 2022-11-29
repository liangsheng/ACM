#include <bits/stdc++.h>
using namespace std;

int T, l, r;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &l, &r);
        if (l * 2 <= r) printf("%d\n", (r - 1) / 2);
        else printf("%d\n", r % l);
    }
    return 0;
}