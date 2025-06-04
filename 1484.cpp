/*
15 = a^2-b^2
16-1
64-49
G <= 100000
a^2-b^2 = 100000?
50000^2 - 49999^2 <= 100000
50000이면 최대 2500000000번 반복
NlogN으로 정해야함. a가 주어질 때 이진 탐색으로 접근
*/
#include <iostream>
using namespace std;
int main() {
    int G;
    cin >> G;
    bool not_exist = true;
    for (int a = 1; a <= 50000; a++) {
        int l = 1, r = a, m, s, res = 0;
        while (l < r) {
            m = (l + r) / 2;
            s = a * a - m * m;
            if (s < G) {
                r = m - 1;
            } else if (s > G) {
                l = m + 1;
            } else {
                res = m;
                break;
            }
        }
        if (a * a - l * l == G) {
            res = l;
        }
        if (res) {
            not_exist = false;
            cout << a << '\n'; //<< ' ' << res << ' ' << a * a - res * res << '\n';
        }
    }
    if (not_exist) {
        cout << -1;
    }
}
