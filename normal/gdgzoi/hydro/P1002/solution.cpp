#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a;
    cin >> a;
    int x = a % 10;
    int y = a / 10 % 10;
    int z = a / 100 % 10;
    cout << x * 100 + y * 10 + z << '\n';
    return 0;
}