#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int H, W;
    while (cin >> H >> W) {
        if (H == 0 && W == 0) break;
        for (int i = 0; i < H; i++) {
            char ch;
            if (i % 2 == 0) ch = '#';
            else ch = '.';
            for (int j = 0; j < W; j++) {
                cout << ch;
                if (ch == '#') ch = '.';
                else ch = '#';
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}