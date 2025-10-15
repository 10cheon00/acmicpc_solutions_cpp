#include <iostream>
int abs(int a) { return a > 0 ? a : -a; }
int min(int a,int b) { return a > b ? b : a; }

using namespace std;
int main() {
    int a,b,c;
    cin >> a >> b >> c;
    int m = min(a,min(b,c)), mmm = -min(-a,min(-b,-c)), s = a+b+c;
    int mm = s - m - mmm;
    if (m+mmm == 2*mm) {
        // ? a b c or a b c ?
        // a + ? == b + c
        cout << s - 2*m;
    } else {
        // a ? b c or a b ? c
        // ? + b == a + c
        cout << m + mmm - mm;
    }
}
