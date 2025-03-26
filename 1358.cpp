/*
직사각형 범위에 있는지 확인
없다면 두 원의 중심과 거리 계산
 */
#include <iostream>
using namespace std;

int dist(int coord[2], int cx, int cy) {
    int x = coord[0] - cx;
    int y = coord[1] - cy;
    return x * x + y * y;
}

int main() {
    int W, H, X, Y, P;
    cin >> W >> H >> X >> Y >> P;
    int R = H / 2;
    int XW = X + W, YH = Y + H;
    int lcx = X, lcy = Y + R, rcx = X + W, rcy = Y + R;
    int coord[2];
    int cnt = 0;
    for (int i = 0; i < P; i++) {
        cin >> coord[0] >> coord[1];
        if (!(coord[0] < X || coord[0] > XW || coord[1] < Y || coord[1] > YH)) {
            cnt++;
        } else {
            if (dist(coord, lcx, lcy) <= R * R || dist(coord, rcx, rcy) <= R * R) {
                cnt++;
            }

        }
    }
    cout << cnt;
}
