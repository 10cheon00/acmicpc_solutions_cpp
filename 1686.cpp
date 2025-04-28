/*
초속 v미터
이동 시에는 m분동안 생존 가능
이동가능한 거리 = 60.0*v*m
dfs 또는 bfs로 이동가능한 거리만 탐색
v=1, m=1이면 1초에 1미터 이동, 1분엔 60미터 이동
sqrt를 쓰지 않을 것이므로 제곱된 값으로 계산
최소로 이동한 거리를 찾아야 하므로, bfs로 이동하되 이동 횟수가 더 작은 경우가 생긴다면 이동
*/

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>

using namespace std;
#define SIZE 1002
int N = 0;
double range = 0;
double arr[SIZE][2];
vector<pair<int, int> > graph[SIZE];

int bfs() {
    int count[SIZE];
    queue<pair<int, int> > q;
    for (int i = 0; i < N; i++) {
        count[i] = -1;
    }

    q.emplace(0, 0);
    while (!q.empty()) {
        int from = q.front().first;
        int c = q.front().second;
        q.pop();
        if (count[from] <= c && count[from] != -1) {
            continue;
        }
        count[from] = c;
        if (from == 1) {
            continue;
        }
        for (int i = 0; i < graph[from].size(); i++) {
            int to = graph[from][i].first;
            int dist = graph[from][i].second;
            if (dist <= range) {
                q.emplace(to, c + 1);
            }
        }
    }
    return count[1];
}

int main() {
    double V, M;
    string line;

    getline(cin, line);
    istringstream output(line);
    output >> V >> M;
    range = V * M * 60.0;
    range *= range;

    while (getline(cin, line)) {
        istringstream output(line);
        output >> arr[N][0];
        output >> arr[N][1];
        // 벙커 간 거리
        for (int to = 0; to < N; to++) {
            double dx = arr[N][0] - arr[to][0];
            double dy = arr[N][1] - arr[to][1];
            double d = dx * dx + dy * dy;
            graph[N].emplace_back(to, d);
            graph[to].emplace_back(N, d);
        }
        N++;
    }

    int n = bfs();
    if (n < 0) {
        cout << "No.";
    } else {
        cout << "Yes, visiting " << n - 1 << " other holes.";
    }
}

/*
1.416 1
0 0
180 180
60 0
120 0
180 60
180 0
180 120
 */
