/*
그래프 탐색문제
100*100크기의 맵에서 탐색한다면 bfs? dfs? 시간초과는?
상하좌우로 모두 이동가능하니까, 최소 이동 횟수를 구하는게 아니라, 최소 거리를 구하는 것
000
010
001
 */
#include <iostream>
#include <queue>
using namespace std;

struct Coord {
    int x, y;

    Coord(int x, int y): x(x), y(y) {
    }
};

struct gt {
    constexpr bool operator()(pair<int, Coord> const &p1, pair<int, Coord> const &p2) const {
        return p1.first > p2.first;
    }
};

int main() {
    int N, M;
    char arr[100][100];
    int d[100][100];
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            d[i][j] = 200;
        }
    }
    priority_queue<pair<int, Coord>, vector<pair<int, Coord> >, gt> q;
    d[0][0] = 0;
    q.emplace(0, Coord(0, 0));

    int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    while (!q.empty()) {
        pair<int, Coord> p = q.top();
        q.pop();
        Coord c = p.second;
        int x = c.x;
        int y = c.y;
        int w = p.first;
        if (x == M - 1 && y == N - 1) {
            break;
        }
        for (int i = 0; i < 4; i++) {
            int dx = x + dir[i][0], dy = y + dir[i][1];
            if (dx >= 0 && dx < M && dy >= 0 && dy < N) {
                int dw = w + (arr[dy][dx] == '1');
                if (d[dy][dx] > dw) {
                    d[dy][dx] = dw;
                    q.emplace(dw, Coord(dx, dy));
                }
            }
        }
    }
    cout << d[N - 1][M - 1];
}
