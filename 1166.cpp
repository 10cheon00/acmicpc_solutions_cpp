//100 1000000000 1000000000 1000000000

#include <iostream>
#define MIN(A, B) ((A) > (B) ? (B) : (A))
using namespace std;
typedef long long LL;
int main() {
    LL N, L, W, H, S;
    cin >> N >> L >> W >> H;
    double l = 0, r = MIN(MIN(L, W), H), A;

    cout << fixed;
    cout.precision(10);
    for (int i=0; i<60;i++) {
        A = (l + r) / 2;
        S = (LL) ((double) L / A) * (LL) ((double) W / A) * (LL) ((double) H / A);
        if (S < N) {
            r = A - 1E-12;
        } else {
            l = A + 1E-12;
        }
    }
    cout << l;
}
