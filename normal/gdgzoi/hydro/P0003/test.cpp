#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < (int) s.size(); i++) {
        // 这是大写字母, 需要转换成小写字母
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] - 'A' + 'a';
        }
    }
    cout << s << endl;
    return 0;
}