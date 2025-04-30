
/*
4
3 1
2 3
3 1
3 2
321
231
213
312
 */
#include <iostream>
using namespace std;

int main() {
    int N, l, r, b=1;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> l >> r;
        if (l==b) {
            b = r;
        } else if (r == b) {
            b = l;
        }
    }
    cout << b;
}
