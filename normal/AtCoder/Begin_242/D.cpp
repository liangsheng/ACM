#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "A";
    cout << s << '\n';
    for (int i = 0; i < 10; i++) {
        string t;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == 'A') t += "BC";
            else if (s[j] == 'B') t += "AC";
            else t += "AB";
        }
        s = t;
        cout << s << '\n';
    }
    return 0;
}