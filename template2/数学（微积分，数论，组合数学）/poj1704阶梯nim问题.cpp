/*
题意：从左到右n个格子，某些有石子，每格永远只能放一个石子，每次可以将某个石子向左移若干格，但不能跨越任何石子。两人轮流操作，谁无路可走谁输。

分析：我们把棋子按位置升序排列后，从后往前把他们两两绑定成一对。如果总个数是奇数，就把最前面一个和边界（位置为0）绑定。 在同一对棋子中，如果对手移动前一个，你总能对后一个移动相同的步数，所以一对棋子的前一个和前一对棋子的后一个之间有多少个空位置对最终的结果是没有影响的。于是我们只需要考虑同一对的两个棋子之间有多少空位。我们把每一对两颗棋子的距离(空位数)视作一堆石子，在对手移动每对两颗棋子中靠右的那一颗时，移动几位就相当于取几个石子,与取石子游戏对应上了,各堆的石子取尽,就相当再也不能移动棋子了。
我们可能还会考虑一种情况，就是某个玩家故意破坏，使得问题无法转换为取石子，例如前一个人将某对中的前者左移，而当前玩家不将这对中的另一移动，则会导致本堆石子增多了，不符合nim。但是这种情况是不会出现的。因为赢家只要按照取石子进行即可获胜，而输家无法主动脱离取石子状态。
*/
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

const int N = 1005;

int T, n;
int p[N];

int main() {
    int i, j, ans;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (i = 1; i <= n; i++) scanf("%d", &p[i]);
        sort(p + 1, p + n + 1);
        ans = 0;
        if (n % 2 == 0) {
            for (i = 1; i <= n; i += 2) ans ^= (p[i + 1] - p[i] - 1);
            if (ans == 0) puts("Bob will win");
            else puts("Georgia will win");
        } else {
            ans = p[1] - p[0] - 1;
            for (i = 2; i <= n; i += 2) ans ^= (p[i + 1] - p[i] - 1);
            if (ans == 0) puts("Bob will win");
            else puts("Georgia will win");
        }
    }
    return 0;
}
