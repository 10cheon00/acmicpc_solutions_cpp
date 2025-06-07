/*
648%6 == 0
648%4 == 0
648%8 == 0
132%1 == 0
132%3 == 0
 */
#include <cmath>
#include <iostream>
typedef long long LL;
using namespace std;
int main() {
    LL N, M, L = 0, H, P;
    cin >> N;
    H = M = N;

    while (1) {
        LL T = N;
        while (T > 0) {
            if (T % 10 != 0 && M % (T % 10)) {
                break;
            }
            T /= 10;
        }
        if (T == 0) {
            cout << M;
            return 0;
        }
        if (H == N || (L > 0 && floor(log10(L + 1)) > floor(log10(P)))) {
            H *= 10;
            P = L + 1;
            L = -1;
        }

        M = H + ++L;
    }
}
