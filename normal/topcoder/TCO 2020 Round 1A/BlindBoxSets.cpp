#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>
#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;

const int N = 52;

int n, m;
double dp[N][N][N][N];

double solve(int i, int j, int k, int l) {
    if (dp[i][j][k][l] >= 0) return dp[i][j][k][l];
    double tmp = 0.0, d = 1.0;
	if (i > 0) tmp += 1.0 * i / n * (solve(i - 1, j + 1, k, l) + 1);
    if (m >= 2 && j > 0) tmp += 1.0 * j / n * (solve(i, j - 1, k + 1, l) + 1);
    if (m >= 3 && k > 0) tmp += 1.0 * k / n * (solve(i, j, k - 1, l + 1) + 1);
    if (m == 4 && l > 0) tmp += 1.0 * l / n * (solve(i, j, k, l - 1) + 1);
    if (m == 1) d = n - i;
    else if (m == 2) d = n - i - j;
    else if (m == 3) d = n - i - j - k;
    else if (m == 4) d = n - i - j - k - l;
    if (d == 0) dp[i][j][k][l] = tmp;
    else dp[i][j][k][l] = tmp * n / (n - d) + d / (n - d);
    // printf("i= %d %d %d %d %f %.4f %.4f\n", i, j, k, l, d, tmp, dp[i][j][k][l]);
    return dp[i][j][k][l];
}

class BlindBoxSets {
    public:
    double expectedPurchases(int numSets, int numItems) {
        n = numItems, m = numSets;
        rep (i, n + 1) rep (j, n + 1) rep (k, n + 1) rep (l, n + 1) dp[i][j][k][l] = -1;
        if (m == 1) dp[0][n][0][0] = 0;
        else if (m == 2) dp[0][0][n][0] = 0;
        else if (m == 3) dp[0][0][0][n] = 0;
        else dp[0][0][0][0] = 0;
        // solve(0, 0, 1, 29);
        return dp[n][0][0][0] = solve(n, 0, 0, 0);
        // return 0.4;
    }
};

// CUT begin
ifstream data("BlindBoxSets.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool double_equal(const double &a, const double &b) { return b==b && a==a && fabs(b - a) <= 1e-9 * max(1.0, fabs(a) ); }

bool do_test(int numSets, int numItems, double __expected) {
    time_t startClock = clock();
    BlindBoxSets *instance = new BlindBoxSets();
    double __result = instance->expectedPurchases(numSets, numItems);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (double_equal(__expected, __result)) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        int numSets;
        from_stream(numSets);
        int numItems;
        from_stream(numItems);
        next_line();
        double __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(numSets, numItems, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1587571044;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "BlindBoxSets (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
