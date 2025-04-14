#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int N;
    cin >> N;
    int c[30][2];
    int mx = 1000, my = 1000, ex = 0, ey = 0;
    for (int i = 0; i < N; i++) {
        cin >> c[i][0] >> c[i][1];
        ex += c[i][0];
        ey += c[i][1];
    }
    cout << ex << ' ' << ey << '\n';
    for (int i = 0; i < N; i++) {
        int dx = ex - c[i][0];
        int dy = ey - c[i][1];
        if (dx * dx + dy*dy < mx * mx + my * my) {
            mx = dx;
            my = dy;
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << sqrt(mx*mx + my*my);
}
