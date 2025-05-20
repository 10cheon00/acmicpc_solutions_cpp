#include <iostream>
typedef long long LL;
using namespace std;
int main() {
    LL W, H, f, c, x1, y1, x2, y2;
    cin >> W >> H >> f >> c >> x1 >> y1 >> x2 >> y2;
    LL row, dy = y2 - y1, col = H / (c+1);
    // f*2 <= W가 아니라면?
    if (f*2 <= W) {
        row = W - f;
    } else {
        row = f;
        f = W - f;
    }
    /*
    |----|///|
    0    f   x1
    |----|---|
    0    x1  f
    |--|///|--|
    0  x1 x2  f
     */
    LL dx = f < x1 ? 0 : (f>x2 ? x2:f) - x1;
    LL fold = f * col - dx * dy, unfold = row * col - (x2 - x1) * dy;
    cout << ((f > 0) * fold + (f < W) * unfold) * (c+1);
}