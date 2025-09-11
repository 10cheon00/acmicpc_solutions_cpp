#include <iostream>
using namespace std;
int s, N, K, R1, R2, C1, C2;
int fractal(int x, int y, int len) {
    int cLen = len / N * K;
    int t = len / 2 - cLen / 2;
    int l = len / 2 - cLen / 2;
    int b = len / 2 + cLen / 2 - (cLen % 2 == 0);
    int r = len / 2 + cLen / 2 - (cLen % 2 == 0);
    if (t <= y && y <= b && l <= x && x <= r) {
        // 검은색 영역
        return 1;
    }
    if (len == N) {
        // N*N일 때에는 예외처리
        return 0;
    }
    // 좌표 조정
    len /= N;
    x %= len;
    y %= len;
    return fractal(x, y, len);
}

int main() {
    cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;
    if (s == 0) {
        cout << 0;
        return 0;
    }
    int len = 1;
    for (int i = 0; i < s; i++) {
        len *= N;
    }
    for (int y = R1; y <= R2; y++) {
        for (int x = C1; x <= C2; x++) {
            printf("%d", fractal(x, y, len));
        }
        puts("");
    }
}