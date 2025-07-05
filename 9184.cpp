#include <iostream>
using namespace std;
/*
if a <= 0 or b <= 0 or c <= 0, then w(a, b, c) returns:
    1

if a > 20 or b > 20 or c > 20, then w(a, b, c) returns:
    w(20, 20, 20)

if a < b and b < c, then w(a, b, c) returns:
    w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)

otherwise it returns:
    w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
 */
int dp[21][21][21] = {0};
int func(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    if (a > 20 || b > 20 || c > 20) {
        dp[a = 20][b = 20][c = 20] = func(20, 20, 20);
    } else if (dp[a][b][c] != 0) {
        return dp[a][b][c];
    } else if (a < b && b < c) {
        dp[a][b][c] = func(a, b, c - 1) + func(a, b - 1, c - 1) - func(a, b - 1, c);
    } else {
        dp[a][b][c] = func(a - 1, b, c) + func(a - 1, b - 1, c) + func(a - 1, b, c - 1) - func(a - 1, b - 1, c - 1);
    }
    return dp[a][b][c];
}
int main() {
    while (1) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) {
            break;
        }
        cout << "w(" << a << ", " << b << ", " << c << ") = " << func(a, b, c) << '\n';
    }
}
