#include <bits/stdc++.h>
using namespace std;

// 请使用引用传值
void swap(int& x, int& y) {
    int t = x;
    x = y;
    y = t;
}

int main() {
    int x, y;
    cin >> x >> y;
    swap(x, y);
    cout << x << ' ' << y << '\n';
    return 0;
}