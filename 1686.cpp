/*
초속 v미터
이동 시에는 m분동안 생존 가능
이동가능한 거리 = 60.0*v*m
dfs 또는 bfs로 이동가능한 거리만 탐색
bfs로 탐색하고, 이동할 수 있는 노드만 생성해서 그래프를 구현
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
vector<int> graph[SIZE];

int bfs() {
    bool visited[SIZE] = {false,};
    queue<pair<int, int> > q;
    q.emplace(0, 0);
    visited[0] = true;

    while (!q.empty()) {
        int from = q.front().first;
        int count = q.front().second;
        if (from == 1) {
            return count - 1;
        }
        q.pop();
        for (int i = 0; i < graph[from].size(); i++) {
            int to = graph[from][i];
            if (!visited[to]) {
                visited[to] = true;
                q.emplace(to, count + 1);
            }
        }
    }
    return -1;
}

int main() {
    double V, M;
    string line;
    getline(cin , line);
    istringstream iss(line);
    iss >> V >> M;
    range = V * M * 60.0;
    range *= range;

    while (getline(cin, line)) {
        istringstream output(line);
        output >> arr[N][0] >> arr[N][1];
        // 벙커 간 거리
        for (int to = 0; to < N; to++) {
            double dx = arr[N][0] - arr[to][0];
            double dy = arr[N][1] - arr[to][1];
            double d = dx * dx + dy * dy;
            if (d <= range) {
                graph[N].emplace_back(to);
                graph[to].emplace_back(N);
            }
        }
        N++;
    }

    int n = bfs();
    if (n < 0) {
        cout << "No.";
    } else {
        cout << "Yes, visiting " << n << " other holes.";
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
