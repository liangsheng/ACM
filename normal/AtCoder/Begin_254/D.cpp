#include <bits/stdc++.h>
#include <ext/rope>
using namespace __gnu_cxx;
using namespace std;

int p;
rope<char> r;
crope cr;

class TextEditor {
public:
    TextEditor() {
        p = 0;
    }
    
    void addText(string text) {
        // r.insert(p, text);
        cr.insert(100, "ffff");
        cout << cr << '\n';
    }
    
    int deleteText(int k) {
        return -1;
    }
    
    string cursorLeft(int k) {
        return "FFF";
    }
    
    string cursorRight(int k) {
        return "FFF";
    }
};

int main() {
    TextEditor* obj = new TextEditor();
    obj->addText("Hello");
    return 0;
}