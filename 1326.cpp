#include <iostream>
#include <queue>
using namespace std;
int N;
int arr[10001];
int dist[10001];
int bfs(int FROM, int TO) {
    queue<pair<int, int>> q; // index, jumpCount
    q.emplace(FROM, 0);
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int i = p.first;
        int cnt = p.second;
        int step = arr[i];
        if (i == TO) {
            return cnt;
        }
        for (int j = i + step; j <= N; j += step) {
            if (dist[j] == 0 || dist[j] > cnt + 1) {
                dist[j] = cnt + 1;
                q.emplace(j, cnt + 1);
            }
        }
        for (int j = i - step; j > 0; j -= step) {
            if (dist[j] == 0 || dist[j] > cnt + 1) {
                dist[j] = cnt + 1;
                q.emplace(j, cnt + 1);
            }
        }
    }
    return -1;
}
int main() {
    int from, to;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d%d", &from, &to);

    int res = bfs(from, to);
    printf("%d", res);
}
/*
10
3 1 1 1
8
3 4 3 2 3 2 1 1
1 8
 */
