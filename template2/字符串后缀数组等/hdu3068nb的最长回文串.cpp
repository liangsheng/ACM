#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)

using namespace std;
int chh;

const int N = 110005 * 2;

int n;
int p[N];
char str[N], s[N];

void kp() {
    int i, id, mx = 0;
    for (i = 1; i < n; i++) {
        if (mx > i) p[i] = min(p[id * 2 - i], mx - i);
        else p[i] = 1;
        for (; str[i + p[i]] == str[i - p[i]]; p[i]++);
        if (p[i] + i > mx) mx = p[i] + i, id = i;
    }
}

int main() {
    int i, j, ans;
    while (~scanf("%s", s)) {
        n = strlen(s);
        str[0] = '$', str[1] = '#';
        for (i = 0; i < n; i++) {
            str[i * 2 + 2] = s[i];
            str[i * 2 + 3] = '#';
        }
        n = 2 * n + 2;
        str[n] = 0;
        kp();
        ans = 0;
        for (i = 0; i < n; i++) ans = max(ans, p[i]);
        printf("%d\n", ans - 1);
    }
    return 0;
}
