#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int N, K, x, y, nx, ny;
    bool block[1001][1001] = {};
    char cmd[501];
    cin >> N >> K;
    // memset(block, 0, sizeof(bool) * 1001 * 1001);
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        block[y + 500][x + 500] = true;
    }
    cin >> cmd;
    x = y = nx = ny = 0;
    for (int i = 0; cmd[i]; i++) {
        if (cmd[i] == 'L') {
            nx = x - 1;
        } else if (cmd[i] == 'R') {
            nx = x + 1;
        } else if (cmd[i] == 'U') {
            ny = y + 1;
        } else if (cmd[i] == 'D') {
            ny = y - 1;
        }
        if (!block[ny + 500][nx + 500]) {
            y = ny;
            x = nx;
        } else {
            ny = y;
            nx = x;
        }
    }
    cout << x << ' ' << y;
}
