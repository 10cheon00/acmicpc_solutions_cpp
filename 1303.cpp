/*
5 5
WBWWW
WWWWW
BBBBB
BBBWW
WWWWW

5 5
WWWWW
BBBBW
WWWBW
WBBBW
WWWWW
 */
#include <iostream>
#include <queue>
using namespace std;
int X, Y;
char map[100][101];
int bfs(int x, int y, char c) {
    bool visited[100][100] = {0};
    int res = 0;
    queue<pair<int, int>> q; // <x, y>
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            if (!visited[i][j]) {
                int cnt = 0;
                q.emplace(j, i);
                while (!q.empty()) {
                    pair<int, int> p = q.front();
                    q.pop();
                    int x = p.first, y = p.second;
                    if (visited[y][x] || map[y][x] != c) {
                        continue;
                    }
                    visited[y][x] = 1;
                    cnt++;
                    if (x > 0)
                        q.emplace(x - 1, y);
                    if (y > 0)
                        q.emplace(x, y - 1);
                    if (x + 1 < X)
                        q.emplace(x + 1, y);
                    if (y + 1 < Y)
                        q.emplace(x, y + 1);
                }
                res += cnt * cnt;
            }
        }
    }
    return res;
}
int main() {
    cin >> X >> Y;
    for (int i = 0; i < Y; i++) {
        cin >> map[i];
    }
    int W = bfs(0, 0, 'W');
    int B = bfs(0, 0, 'B');
    cout << W << ' ' << B;
}
