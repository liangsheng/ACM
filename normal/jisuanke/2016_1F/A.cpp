#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

#define X first
#define Y second
#define pb push_back
#define mp make_pair

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

int n;
string s;

bool gao() {
    int i;
    if (n < 2) return 0;
    if (s[0] != s[n - 1]) return 0;
    if (s[0] != '\"' && s[0] != '\'') return 0;
    if (s[0] == '\"') {
        for (i = 0; i < n; i++) {
            if (s[i] == '\"') s[i] = '\'';
            else if (s[i] == '\'') s[i] = '\"';
        }
    }
    for (i = 1; i <= n - 2; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') continue;
        if (s[i] == '\"') continue;
        if (s[i] == '\'') return 0;
        if (i + 1 <= n - 2 && (s[i + 1] == '\'' || s[i + 1] == '\\' || s[i + 1] == '\"')) {
            i++;
            continue;
        }
        return 0;
    }
    return 1;
}

int main() {
    //string dd = "\'\'"'\'";
    //cout << dd << '\n';
    while (cin >> s) {
        n = s.size();
        puts(gao() ? "Yes" : "No");
    }
    return 0;
}
