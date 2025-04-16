/*
직교 다각형이므로, 변을 이루는 두 점은 항상 x나 y가 같은 좌표일 것임..
정렬 잘하고, 순서대로 두 점간의 거리를 누적시키면 될 것 같은데
임의의 점 p에서 x나 y가 같은 점이 여러 개 등장할 수 있다.

하지만 p에서 변을 만들기 위해선 이전에 선택했던 방향과
 같은 방향을 고를 수 없다. 무조건 틀어야함.
문제는 길이만 구하면 되므로, 직교 다각형을 만들 필요가 있을까?
+--------+
|  +-+   |
+--+ +---+
0123456789
8
9 2
3 1
5 0
0 2
5 1
3 0
0 0
9 0
   ^
   `-- 얘는 가장 가까운 점이 오른쪽 점인데, 실제로는 왼쪽과 연결되어야 한다.
       따라서, 좌표값이 작은 점부터 선택해야함.
       정렬할 땐 x나 y가 같아야함
+--+
+--------+
   +-+
     +---+
3+9+2+4=18
++
||++
++++
2+2+1+1=6
점 개수가 100000이라서 o(N^2)면 안된다.
x를 정렬할 땐 y가 같은 것부터, y가 같다면 x가 작은것부터
 */
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
struct Coord {
    int x, y;
};
bool x_compare(Coord& c1, Coord& c2) {
    if (c1.y == c2.y) {
        return c1.x < c2.x;
    }
    return c1.y < c2.y;
}

bool y_compare(Coord& c1, Coord& c2) {
    if (c1.x == c2.x) {
        return c1.y < c2.y;
    }
    return c1.x < c2.x;
}
int main() {
    int N;
    cin >> N;
    Coord c[100000];
    for (int i=0; i<N; i++) {
        cin >> c[i].x >> c[i].y;
    }
    int len = 0;
    // x 길이 계산
    sort(c, c+N, x_compare);
    for (int i=0; i<N; i+=2) {
        len += abs(c[i].x - c[i+1].x);
    }
    // y 길이 계산
    sort(c, c+N, y_compare);
    for (int i=0; i<N; i+=2) {
        len += abs(c[i].y - c[i+1].y);
    }
    cout << len;
}