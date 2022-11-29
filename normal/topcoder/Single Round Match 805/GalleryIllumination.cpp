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

class GalleryIllumination {
    public:
    int countDarkCells(int R, int C, vector<string> g) {
        int ans = 0;
        for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) {
            if (g[i][j] != '.') continue;
            bool flag = 0;
            for (int k = i - 1; k >= 0; k--) {
                if (g[k][j] == 'O') {
                    flag = 1;
                    break;
                }
                if (g[k][j] == '#') break;
            }
            for (int k = i + 1; k < R; k++) {
                if (g[k][j] == 'O') {
                    flag = 1;
                    break;
                }
                if (g[k][j] == '#') break;
            }
            for (int k = j - 1; k >= 0; k--) {
                if (g[i][k] == 'O') {
                    flag = 1;
                    break;
                }
                if (g[i][k] == '#') break;
            }
            for (int k = j + 1; k < C; k++) {
                if (g[i][k] == 'O') {
                    flag = 1;
                    break;
                }
                if (g[i][k] == '#') break;
            }
            ans += flag == 0;
        }
        return ans;
    }
};

// CUT begin
ifstream data("GalleryIllumination.sample");

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

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
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

bool do_test(int R, int C, vector<string> floorPlan, int __expected) {
    time_t startClock = clock();
    GalleryIllumination *instance = new GalleryIllumination();
    int __result = instance->countDarkCells(R, C, floorPlan);
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
        int R;
        from_stream(R);
        int C;
        from_stream(C);
        vector<string> floorPlan;
        from_stream(floorPlan);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(R, C, floorPlan, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1620489921;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 300 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "GalleryIllumination (300 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
