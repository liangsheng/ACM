#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)

using namespace std;
int chh;

const int N = 10001;

struct Hash {
    int sx[N], sy[N], nxt[N], head[N], e;

    void init() {
        e = 0;
        memset(head, -1, sizeof(head));
    }

    bool update(int x, int y, bool f) {
        int i, c = (x * y + N) % N;
        for (i = head[c]; i != -1; i = nxt[i]) {
            if (sx[i] == x && sy[i] == y) return 0;
        }
        if (! f) return 1;
        sx[e] = x, sy[e] = y, nxt[e] = head[c], head[c] = e++;
        return 1;
    }
} q;

int dirx[4] = {0, -1, 0, 1};
int diry[4] = {1, 0, -1, 0};

struct RotatingBot {
    int minArea(vector<int> moves) {
        int i, j, n = moves.size();
        int l1, l2, t1, t2, sx, sy, f;
        l1 = l2 = t1 = t2 = sx = sy = f = 0;
        q.init();
        q.update(sx, sy, 1);
        for (i = 0; i < n; i++) {
            if (f == 0) {
                for (j = 1; j <= moves[i]; j++) {
                    if (! q.update(sx, ++sy, 1)) return -1;
                }
                l2 = max(l2, sy);
            } else if (f == 1) {
                for (j = 1; j <= moves[i]; j++) {
                    if (! q.update(--sx, sy, 1)) return -1;
                }
                t1 = min(t1, sx);
            } else if (f == 2) {
                for (j = 1; j <= moves[i]; j++) {
                    if (! q.update(sx, --sy, 1)) return -1;
                }
                l1 = min(l1, sy);
            } else if (f == 3) {
                for (j = 1; j <= moves[i]; j++) {
                    if (! q.update(++sx, sy, 1)) return -1;
                }
                t2 = max(t2, sx);
            }
            f = (f + 1) % 4;
        }
        sx = sy = f = 0;
        q.init();
        q.update(sx, sy, 1);
        for (i = 0; i < n; i++) {
            for (j = 1; j <= moves[i]; j++) {
                sx += dirx[f], sy += diry[f];
                q.update(sx, sy, 1);
            }
            if (i != n - 1) {
                bool flag = 0;
                int x = sx + dirx[f], y = sy + diry[f];
                if (y < l1 || y > l2 || x < t1 || x > t2) flag = 1;
                if (! q.update(x, y, 0)) flag = 1;
                if (! flag) return -1;
            }
            f = (f + 1) % 4;
        }
        return (l2 - l1 + 1) * (t2 - t1 + 1);
    }
};

int main() {
    int i, j, n;
    RotatingBot a;
    vector<int> b;
    while (~scanf("%d", &n)) {
        b.clear();
        for (i = 0; i < n; i++) {
            scanf("%d", &j);
            b.push_back(j);
        }
        printf("%d\n", a.minArea(b));
    }
    return 0;
}
