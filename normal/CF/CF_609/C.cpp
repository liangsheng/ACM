#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 200005;

int n, k;
string a;

void gao() {

    cout << n << '\n';
    string b;
    for (int i = 0; i < n; i++) b += a[i % k];
    if (b >= a) {
        cout << b << '\n';
        return ;
    }
    for (int i = k - 1; i >= 0; i--) {
        if (a[i] == '9') a[i] = '0';
        else {
            a[i] ++;
            break;
        }
    }
    for (int i = 0; i < n; i++) b[i] = a[i % k];
    cout << b << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n >> k) {
        cin >> a;
        gao();
    }
    return 0;
}
