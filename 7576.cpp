/*
빈 칸
안익은 토마토
익은 토마토
익은 토마토는 상하좌우로 뻗어나아감
빈칸으로는 뻗어나가지 않음
***@
*...
*...
****
크기가 1000x1000이므로, bfs로 탐색하면? 1000000번...
토마토 주변이 -1로 막혀있다면 절대 익을 수 없음... 이건 익은 개수와 안익은 개수로 판단
3 3
1 0 0
0 0 -1
0 -1 0
*/
#include <iostream>
#include <queue>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M, notripe = 0;
    queue<pair<int, int> > q;

    cin >> M >> N;
    int **map = new int *[N];
    int **day = new int *[N];

    for (int i = 0; i < N; i++) {
        map[i] = new int[M];
        day[i] = new int[M];

        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) {
                notripe++;
            }
            day[i][j] = 0;
            if (map[i][j] == 1) {
                q.push({i, j});
            }
        }
    }
    if (notripe == 0) {
        cout << 0;
        return 0;
    }
    int lastDay = 0;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        int today = day[y][x];
        lastDay = lastDay > today ? lastDay : today;
        if (x > 0 && map[y][x - 1] == 0) {
            q.emplace(y, x - 1);
            notripe--;
            day[y][x - 1] = today + 1;
            map[y][x - 1] = 1;
        }
        if (y > 0 && map[y - 1][x] == 0) {
            q.push({y - 1, x});
            notripe--;
            day[y - 1][x] = today + 1;
            map[y - 1][x] = 1;
        }
        if (x < M - 1 && map[y][x + 1] == 0) {
            q.push({y, x + 1});
            notripe--;
            day[y][x + 1] = today + 1;
            map[y][x + 1] = 1;
        }
        if (y < N - 1 && map[y + 1][x] == 0) {
            q.push({y + 1, x});
            notripe--;
            day[y + 1][x] = today + 1;
            map[y + 1][x] = 1;
        }
    }

    if (notripe > 0) {
        cout << -1;
        return 0;
    }
    cout << lastDay;
}
