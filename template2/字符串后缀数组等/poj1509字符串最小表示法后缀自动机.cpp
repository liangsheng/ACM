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

inline void in(int &t) {
    int n = 0, s = 1;
    char ch = getchar();
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') s = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') n = n * 10 + ch - '0', ch = getchar();
    t = n * s;
}

inline void in_s(char str[]) {
    int e = 0;
    char ch = getchar();
    while (ch == '\n' || ch == ' ') ch = getchar();
    str[e++] = ch, ch = getchar();
    while (ch != ' ' && ch != '\n') str[e++] = ch, ch = getchar();
    str[e++] = 0;
}

const int N = 10005, CH = 26;

struct node {
    node *ch[26], *f;
    int l, x;
} a[N << 2], *head, *last;

int top;

void init() {
    memset(a, 0, sizeof(a));
    top = -1;
    head = last = &a[++top];
}

void add(int x) {
    node *p = &a[++top], *bj = last;
    p -> l = last -> l + 1, p -> x = p -> l, last = p;
    for (; bj && !bj -> ch[x]; bj = bj -> f) bj -> ch[x] = p;
    if (!bj) p -> f = head;
    else if (bj -> ch[x] -> l == bj -> l + 1) p -> f = bj -> ch[x];
    else {
        node *r = &a[++top], *q = bj -> ch[x];
        *r = *q, r -> l = bj -> l + 1, r -> x = p -> l, p -> f = q -> f = r;
        for (; bj && bj -> ch[x] == q; bj = bj -> f) bj -> ch[x] = r;
    }
}

int T, n;
char s[N];

int main() {
    int i, j;
    in(T);
    while (T--) {
        scanf("%s", s);
        n = strlen(s);
        init();
        for (i = 0; i < n; i++) add(s[i] - 'a');
        for (i = 0; i < n; i++) add(s[i] - 'a');
        last = head;
        for (i = 0; i < n; i++) {
            for (j = 0; j < 26; j++) {
                if (last -> ch[j]) {
                    last = last -> ch[j];
                    break;
                }
            }
        }
        printf("%d\n", last -> x - n + 1);
    }
    return 0;
}
