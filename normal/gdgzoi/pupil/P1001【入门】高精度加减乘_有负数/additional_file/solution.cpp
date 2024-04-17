#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

struct BigInt {

    int n, f;  // n 是位数, f = 1 是正数, f = -1 是负数
    int a[N];
    
    BigInt(): n(0), f(1) {}
    
    BigInt(int x) {
        n = 0, f = (x < 0 ? -1 : 1);
        x = f * x;
        while (x != 0) a[n++] = x % 10, x /= 10;
    }
    
    BigInt(string& A) {
        n = 0, f = (A[0] == '-' ? -1 : 1);
        for (int i = (int) A.size() - 1; i >= (f == -1 ? 1 : 0); i--) a[n++] = A[i] - '0';
    }
    
    BigInt& operator =(int x) {
        n = 0, f = (x < 0 ? -1 : 1);
        x = f * x;
        while (x != 0) a[n++] = x % 10, x /= 10;
        return *this;
    }
    
    BigInt& operator =(const BigInt& x) {
        n = 0, f = x.f;
        for (int i = 0; i < x.n; i++) a[n++] = x.a[i];
        return *this;
    }
    
    void arrange() {
        f = 1;
        for (int i = 0; i < n; i++) if (a[i] != 0) f = (a[i] < 0 ? -1 : 1);
        
        int d = 0;  // 借位或者进位
        for (int i = 0; i < n; i++) {
            int t = a[i] * f + d;
            a[i] = t % 10;
            d = t / 10;
            if (a[i] < 0) a[i] += 10, d--;
        }
        if (d > 0) a[n++] = d;
        while (n > 1 && a[n - 1] == 0) n--; 
    }
    
    BigInt operator +(const BigInt& x) {
        BigInt z;
        z.n = max(n, x.n);
        for (int i = 0; i < z.n; i++) z.a[i] = 0;
        for (int i = 0; i < n; i++) z.a[i] += f * a[i];
        for (int i = 0; i < x.n; i++) z.a[i] += x.f * x.a[i];
        z.arrange();
        return z;
    }

    BigInt operator +(int x) {
        BigInt w = x;
        return *this + w;
    }
    
    BigInt operator -(const BigInt& x) {
        BigInt w = x;
        w.f *= -1;
        return *this + w;
    }
    
    BigInt operator -(int x) {
        BigInt w = x;
        return *this - w;
    }

    BigInt operator *(const BigInt& x) {
        BigInt z;
        z.n = n + x.n - 1;
        for (int i = 0; i < z.n; i++) z.a[i] = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < x.n; j++) z.a[i + j] += f * a[i] * x.f * x.a[j];
        z.arrange();
        return z;
    }
    
    BigInt operator *(int x) {
        BigInt w = x;
        return *this * w;
    }
    
    void print() {
        if (n == 0) cout << 0 << '\n';
        else {
            if (f == -1) cout << '-';
            for (int i = n - 1; i >= 0; i--) cout << a[i];
            cout << '\n';
        }
    }
};

int main() {
    int T;
    string A, B;
    cin >> T;
    while (T--) {
        cin >> A >> B;
        BigInt a(A), b(B);
        
        // 加法
        BigInt x = a + b;
        x.print();
        
        // 减法
        BigInt y = a - b;
        y.print();

        // 乘法
        BigInt z = a * b;
        z.print();
    }
    return 0;
}