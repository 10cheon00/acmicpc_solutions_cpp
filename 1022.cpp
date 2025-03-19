// 극 좌표계로 푸는 문제가 아니라,
// 중심 축에서 얼마나 멀리 떨어져 있냐로 풀어야 할듯
/*

     \   ?<-------+
       \  (3)     |
         \        |
     ? (2) 1  (4) | ---> x
     ^       9    |
     |    (1)  25 |
     +-----------49
           |
           |
           y
1에선 dx, dy빼기
2에선 dx, dy빼기
3에선 세로, dy빼고 가로-dx빼기
4에선 세로, 가로빼고, 가로빼고, 세로-dy빼기
세로 가로는 2 * r
 */
#include <iomanip>
#include<iostream>
using namespace std;
int ranges[5001];

int abs(int a) {
    return a > 0 ? a : -a;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int len(int x) {
    if (x == 0) {
        return 0;
    }
    return 1 + len(x / 10);
}

int get(int x, int y) {
    int r = max(abs(x), abs(y));
    int pivot = ranges[r];
    int dx = abs(x - r);
    int dy = abs(y - r);
    // 위치에 따라 사분면 생각하기
    if (x <= y) {
        // 1, 2
        // return 1;
        return pivot - dx - dy;
    }
    int len = 2 * r;
    if (abs(y) > x) {
        // 3
        return pivot - 2 * len - dy + dx;
    }
    // 4
    return pivot - 4 * len + dy + dx;
}

int main() {
    // cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i <= 5000; i++) {
        ranges[i] = 2 * (i + 1) - 1;
        ranges[i] *= ranges[i];
    }
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    int maxlen = 0;
    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            maxlen = max(maxlen, len(get(j, i)));
        }
    }
    char format[5] = {'%', (char)(maxlen + '0'), 'd', ' ', '\0'};

    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            printf(format, get(j, i));
        }
        puts("");
    }
}
