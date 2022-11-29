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

using namespace std;

    // int get_id(int month, int day) {
    //     int d[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    //     int ans = 0;
    //     for (int i = 0; i < month - 1; i++) ans += d[i];
    //     return ans + day;
    // }

    // int get_we(int month, int day) {
    //     int ans = get_id(month, day) - 1;
    //     ans = ans % 7;
    //     if (ans <= 5) return ans + 2;
    //     return 1;
    // }

class SaturdayNightStay {
    
    int get_id(int month, int day) {
        int d[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int ans = 0;
        for (int i = 0; i < month - 1; i++) ans += d[i];
        return ans + day;
    }

    int get_we(int id) {
        int ans = id - 1;
        ans = ans % 7;
        if (ans <= 5) return ans + 2;
        return 1;
    }

    public:
    int countOptions(int firstDay, int firstMonth, int lastDay, int lastMonth) {
        int x = get_id(firstMonth, firstDay);
        int y = get_id(lastMonth, lastDay);
        // cout << "x= " << x << " y= " << y << '\n';
        int ans = 0, e = 0;
        int a[400];
        for (int i = x; i <= y; i++) a[e++] = get_we(i);
        // for (int i = 0; i < e; i++) cout << a[i] << ' ';
        // puts("");
        for (int i = 0; i < e; i++) for (int j = i + 1; j < e; j++) {
            bool ok = 0;
            for (int k = i; k < j; k++) {
                if (a[k] == 6) {
                    ok = 1;
                    break;
                }
            }
            ans += ok;
        }
        return ans;
    }
};

// CUT begin
ifstream data("SaturdayNightStay.sample");

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

bool do_test(int firstDay, int firstMonth, int lastDay, int lastMonth, int __expected) {
    time_t startClock = clock();
    SaturdayNightStay *instance = new SaturdayNightStay();
    int __result = instance->countOptions(firstDay, firstMonth, lastDay, lastMonth);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
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
        int firstDay;
        from_stream(firstDay);
        int firstMonth;
        from_stream(firstMonth);
        int lastDay;
        from_stream(lastDay);
        int lastMonth;
        from_stream(lastMonth);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(firstDay, firstMonth, lastDay, lastMonth, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1560582133;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    // int x, y;
    // while (cin >> x >> y) cout << get_we(x, y) << '\n';
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
        cout << "SaturdayNightStay (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
