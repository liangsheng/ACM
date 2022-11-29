#include <bits/stdc++.h>
using namespace std;

template <typename T, class F = function<T(const T&, const T&)> >
class SparseTable {
public:
    int n;
    vector< vector<T> > mat;
    F func;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}