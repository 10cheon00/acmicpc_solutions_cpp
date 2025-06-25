#include <iostream>
#include <queue>
struct coord {
    int z, y, x;
    int t;
};
using namespace std;
int map[100][100][100];
bool visited[100][100][100];
int M, N, H, cnt = 0;

int d[6][3] = {{-1, 0, 0}, {0, -1, 0}, {1, 0, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1}};
queue<coord> q;
int bfs() {
    int res = 0;
    while (!q.empty()) {
        coord c = q.front();
        q.pop();
        int x = c.x, y = c.y, z = c.z, t = c.t;
        res = res > t ? res : t;
        for (int i = 0; i < 6; i++) {
            int dx = x + d[i][0], dy = y + d[i][1], dz = z + d[i][2];
            if (dx < 0 || dy < 0 || dz < 0 || dx >= M || dy >= N || dz >= H) {
                continue;
            }
            if (map[dz][dy][dx] == 0) {
                map[dz][dy][dx] = 1;
                q.emplace((coord) {dz, dy, dx, t + 1});
                cnt--;
            }
        }
    }
    return cnt == 0 ? res : -1;
}
int main() {
    cin >> M >> N >> H;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> map[i][j][k];
                if (map[i][j][k] == 1) {
                    q.emplace((coord) {i, j, k, 0});
                }
                if (map[i][j][k] == 0) {
                    cnt++;
                }
                // if (map[i][j][k] == 0) {
                //     visited[i][j][k] = false;
                // } else {
                //     visited[i][j][k] = true;
                // }
            }
        }
    }
    cout << bfs();
}
