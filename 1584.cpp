/*
지불해야할 생명력의 최솟값 구하기 항상 최선의 선택을 하기?
방문했던 곳을 다시 갈 필요는 없음
1
0 0 499 500
0
--> 오른쪽으로 끝까지 간 다음 아래로 간다면 499
 */

#include <iostream>
#include <queue>
using namespace std;
#define INF ~(1<<31)
int N, M;
int dead[50][4], danger[50][4];
int d[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};
int visited[501][501];
priority_queue<pair<int, pair<int, int>>> pq;

bool intersect(int x, int y, int *coord) { return coord[0] <= x && x <= coord[2] && coord[1] <= y && y <= coord[3]; }

bool valid(int x, int y) { return !(x < 0 || y < 0 || x > 500 || y > 500); }

int bfs(int x, int y) {
    int res = INF;
    pq.emplace(0, make_pair(x, y));
    while (!pq.empty()) {
        auto p = pq.top();
        int life = -p.first;
        x = p.second.first, y = p.second.second;
        pq.pop();

        if (x == 500 && y == 500) {
            res = res > life ? life : res;
            continue;
        }
        // visited[y][x] = life;
        // cout << visited[y][x] << ' ' << life << ':' << x << ' ' << y << '\n';
        for (int i = 0; i < 4; i++) {
            int xx = x + d[i][0], yy = y + d[i][1];
            if (!valid(xx, yy)) {
                continue;
            }

            // 죽음의 구역 검사
            bool flag = false;
            for (int j = 0; j < M; j++) {
                if (intersect(xx, yy, dead[j])) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                continue;
            }

            // 위험한 구역 검사
            flag = false;
            for (int j = 0; j < N; j++) {
                if (intersect(xx, yy, danger[j])) {
                    flag = true;
                    break;
                }
            }
            if (visited[yy][xx] > life + flag) {
                visited[yy][xx] = life + flag;
                pq.emplace(-(life + flag), make_pair(xx, yy));
            }
        }
    }

    return res < INF ? res : -1;
}

void swap(int* p1, int* p2) {
    int t = *p1;
    *p1 = *p2;
    *p2 = t;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> danger[i][0] >> danger[i][1] >> danger[i][2] >> danger[i][3];
        if (danger[i][0] > danger[i][2]) {
            swap(&danger[i][0], &danger[i][2]);
        }
        if (danger[i][1] > danger[i][3]) {
            swap(&danger[i][1], &danger[i][3]);
        }
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> dead[i][0] >> dead[i][1] >> dead[i][2] >> dead[i][3];
        if (dead[i][0] > dead[i][2]) {
            swap(&dead[i][0], &dead[i][2]);
        }
        if (dead[i][1] > dead[i][3]) {
            swap(&dead[i][1], &dead[i][3]);
        }
    }
    for (int i=0; i<=500;i++) {
        for (int j=0; j<=500; j++) {
            visited[i][j] = INF;
        }
    }
    cout << bfs(0, 0);
}
