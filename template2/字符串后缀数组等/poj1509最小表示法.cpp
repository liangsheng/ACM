#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define lowbit(x) ((x) & (-(x)))

using namespace std;
int chh;

const int N = 10005;

int T, n;
char s[N * 2];

int solve(char s[N]) {
    int i, j, k, n = strlen(s);
    for (i = n; i < 2 * n; i++) s[i] = s[i - n];
    s[n * 2] = 0;
    i = 0, j = 1, k = 0;
    while (i < n && j < n && k < n) {
        if (s[i + k] == s[j + k]) k++;
        else {
            if (s[i + k] > s[j + k]) i += k + 1;
            else j += k + 1;
            if (i == j) j++;
            k = 0;
        }
    }
    return min(i, j);
}

int main() {
    int i, j;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        printf("%d\n", solve(s) + 1);
    }
    return 0;
}
