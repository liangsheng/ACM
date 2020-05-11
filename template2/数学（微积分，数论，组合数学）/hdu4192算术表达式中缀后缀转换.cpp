#include<iostream>
#include<stack>
using namespace std;

int op(char x) {
    if (x == '+')return 1;
    else if (x == '-')return 1;
    else if (x == '*')return 2;
    else if (x == '/')return 2;
    else return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string ex;
        string tmp = "";
        stack<char> a, b;
        cin >> ex;

        //中缀转换为后缀。
        for (int i = 0; i < ex.length(); i++) {
            if (ex[i] >= 'a' && ex[i] <= 'z')tmp += ex[i];
            else if (ex[i] == '(') a.push(ex[i]);
            else if (ex[i] == ')') {
                while (a.top() != '(') {
                    tmp += a.top();
                    a.pop();
                }
                a.pop();
            } else {
                if (a.empty() || op(ex[i]) > op(a.top()))a.push(ex[i]);
                else {
                    while (op(ex[i]) <= op(a.top())) {
                        tmp += a.top();
                        a.pop();
                        if (a.empty())break;
                    }
                    a.push(ex[i]);
                }
            }
        }
        while (!a.empty()) {
            tmp += a.top();
            a.pop();
        }
        cout << tmp << endl;
        //后缀转回中缀
        stack<char> ope;
        stack<string> opn;
        string tmp1, tmp2;
        for (int i = 0; i < tmp.length(); i++) {
            if (tmp[i] >= 'a' && tmp[i] <= 'z') {
                string tt = "";
                tt += tmp[i];
                opn.push(tt);
                ope.push(tmp[i]);
            } else {
                if (op(ope.top()) != 0 && (op(tmp[i]) > op(ope.top()) || (op(tmp[i]) == op(ope.top()) && (tmp[i] == '-' || tmp[i] == '/')))) {
                    tmp2 = "(";
                    tmp2 += opn.top();
                    tmp2 += ")";
                } else tmp2 = opn.top();
                opn.pop();
                ope.pop();
                if (op(ope.top()) != 0 && op(tmp[i]) > op(ope.top())) {
                    tmp1 = "(";
                    tmp1 += opn.top();
                    tmp1 += ")";
                } else tmp1 = opn.top();
                ope.pop();
                opn.pop();
                tmp1 += tmp[i];
                tmp1 += tmp2;
                opn.push(tmp1);
                ope.push(tmp[i]);
            }
        }
        cout << opn.top() << endl;
    }
    return 0;
}
