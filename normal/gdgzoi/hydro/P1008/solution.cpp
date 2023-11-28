#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long long n, cnt = 1;
    cin >> n;
    while (n != 1) {
        if (n % 2 == 0) n /= 2;
        else n = n * 3 + 1;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}