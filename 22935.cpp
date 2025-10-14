/*
1 2 ... 14 15 16 17 ... 28 29 30 ...
1 2 ... 14 15 14 13 ...  2  1  2 ...
 */
#include <iostream>
using namespace std;

int main() {
    int N, T;
    cin >> N;
    int code[29] = {2, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2};
    for (int i = 0; i < N; i++) {
        cin >> T;
        T = T % 28;
        int U = 8;
        while (U) {
            cout << (code[T] & U ? "딸기" : "V");
            U >>= 1;
        }
        cout << '\n';
    }
}

