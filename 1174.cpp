/*
210
310
320
321
3210

4210
4310
4320
4321

5210
5310
5320
5321
5410
5420
5421
5430
5431
5432
10~99 : 1 + 2 + ... 8
100~999 : 1 + (1+2) + (1+2+3) + .. + (1+2+..+8)
1000~9999 : 1 + (1 + 1+2) + (1 + 1+2 + 1+2+3) ...
없다면, 9876543210보다 큰 수를 탐색할 때
i++로 탐색하면 시간초과
 */

#include <iostream>
using namespace std;

long long comb(int a[10]) {
    long long res = 0;
    for (int i = 9; i >= 0; i--) {
        res = res * 10 + a[i];
    }
    return res;
}

int main() {
    int N, M = 10, a[10] = {0, 1}, L = 1;
    // 0 1
    // 0 2
    // 1 2
    // 0 3
    // 1 3
    // 2 3
    // 0 1 2
    // 0 1 3
    // 0 2 3
    // 1 2 3
    // 0 1 4
    cin >> N;
    if (N <= 10) {
        cout << N - 1;
        return 0;
    }
    if (N > 1023) {
        cout << -1;
        return 0;
    }
    while (1) {
        // 다음 감소하는 수 만들기
        while (a[0] < a[1]) {
            M++;
            if (M == N) {
                cout << comb(a) << '\n';
                return 0;
            }
            ++a[0];
        }
        for (int i = 1; i <= L; i++) {
            if (a[i - 1] == a[i]) {
                if (i == L && a[i] == 9) {
                    ++L;
                    a[L] = L;
                    for (int j=L-1; j>=0; j--) {
                        a[j] = j;
                    }
                } else {
                    a[i - 1] = i - 1;
                    ++a[i];
                }
            }
        }
    }
}
