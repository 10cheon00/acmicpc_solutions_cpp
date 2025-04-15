#include <iostream>
#include <cmath>
using namespace std;

double dist(double x1, double y1, double x2, double y2) {
    double dx = x1 - x2, dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    int N, R, x1, y1, x2, y2, x3, y3, x4, y4, cnt = 0;
    cin >> N >> R;
    for (int i = 0; i < N; i++) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        double cx = (x1 + x2 + x3 + x4) / 4.0, cy = (y1 + y2 + y3 + y4) / 4.0;
        double cr = dist(cx, cy, x1, y1);
        double R_ = R + cr;
        if (R_ >= dist(0, 0, cx, cy)) {
            cnt++;
        }
    }
    cout << cnt;
}
