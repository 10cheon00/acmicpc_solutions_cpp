/*
5 5
5 -5
-5 5
-5 -5
----
((5,5)  , (-5,5))
((-5,-5), (5,-5))
----
|(0,0), (0,0)|              => 0

-100000 -100000
100000 100000
|(-10^5,-10^5),(10^5,10^5)| => 282842.###
벡터를 만드는 것은 두 점.
점을 두 그룹으로 나누어 분류하고(그룹에서 점의 순서는 상관없음)
각 점의 좌표값을 모두 더해 만든 벡터의 길이를 구했을 때 그 값이 최소가 되도록 만들자

문제와 부합하도록 점을 두 그룹으로 잘 분류했다고 가정.
그 그룹 내의 점들을 각각 위치벡터로 보고 그 벡터들을 모두 더해 얻은 벡터를 각각 OA, OB로 둔다면
 A과 B의 거리가 문제에서 요구하는 출력값.

N이 최대 20...
집합에서 10개를 뽑는 경우의 수 20C10 = 184756
 */
#include <cmath>
#include <float.h>
#include <iostream>
using namespace std;

typedef struct {
    int x, y;
} Coord;

int N;
double res;
int check[20];
Coord coord[20];

void solution() {
    Coord c1 = {0, 0}, c2 = {0, 0};
    for (int i = 0; i < N; i++) {
        if (check[i]) {
            c1.x += coord[i].x;
            c1.y += coord[i].y;
        } else {
            c2.x += coord[i].x;
            c2.y += coord[i].y;
        }
    }
    long long dx = c1.x - c2.x;
    long long dy = c1.y - c2.y;
    double dist = sqrt(dx *dx+ dy*dy);
    res = res > dist ? dist : res;
}

void dfs(int idx, int chosen) {
    const int K = N / 2;

    // K개 다 골랐으면 콜백
    if (chosen == K) {
        solution();
        return;
    }
    // 끝까지 갔는데 모자라면 종료
    if (idx == N)
        return;

    // 가지치기: 남은 칸으로 K-chosen 개 못 채우면 컷
    if (N - idx < K - chosen)
        return;

    // 1) idx를 고른다
    check[idx] = 1;
    dfs(idx + 1, chosen + 1);

    // 2) idx를 고르지 않는다
    check[idx] = 0;
    dfs(idx + 1, chosen);
}

int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> coord[i].x >> coord[i].y;
        }
        res = DBL_MAX;
        dfs(0, 0);
        cout << fixed;
        cout.precision(15);
        cout << res << '\n';
    }
}
