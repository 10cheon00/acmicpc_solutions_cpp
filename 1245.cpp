/*
3 4
1 1 2 3
1 1 2 2
1 1 2 3
*/
#include <iostream>
#include <queue>
using namespace std;
int N, M;
int map[100][70];
int d[8][2] = { -1,-1 , 0,-1 , 1,-1 , -1,0 , 1,0 , -1,1 , 0,1 , 1,1 };
int cnt = 0;
bool check[100][70] = { false };

void bfs(int sx, int sy, int k) {
    queue<pair<int, int>> q;
    bool visit[100][70] = { false };
    q.emplace(sx, sy);
    // k와 같은 값만 가진 노드만 선택해 bfs
    // k보다 큰 수를 만났다면 즉시 탈출
    check[sy][sx] = true;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        visit[y][x] = true;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int dx = x + d[i][0], dy = y + d[i][1];
            if (dx < 0 || dy < 0 || dy >= N || dx >= M) {
                continue;
            }
            if (visit[dy][dx]) {
                continue;
            }
            if (map[dy][dx] == k) {
                q.emplace(dx, dy);
                check[dy][dx] = true;
            }
            if (map[dy][dx] > k) {
                return;
            }
        }
    }
    cnt++;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!check[i][j]) {
                bfs(j, i, map[i][j]);
            }
        }
    }
    cout << cnt;
}