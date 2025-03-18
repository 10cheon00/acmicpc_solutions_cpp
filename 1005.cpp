#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> P;

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 방향 그래프를 뒤집는다.
    int t, n, k;
    cin >> t;
    while (t-- > 0) {
        int weights[1001], from, to, dest, costs[1001];
        cin >> n >> k;
        vector<P> graph[1001];
        vector<int> leafs;
        for (int i = 1; i <= n; i++) {
            cin >> weights[i];
            costs[i] = 0;
        }
        for (int i = 0; i < k; i++) {
            cin >> from >> to;
            graph[to].push_back(make_pair(from, weights[from]));
        }

        cin >> dest;
        // bfs로 탐색
        queue<int> q;
        q.push(dest);
        costs[dest] = weights[dest];
        while (!q.empty()) {
            from = q.front();
            q.pop();
            if (graph[from].empty()) {
                leafs.push_back(from);
                continue;
            }
            for (int i = 0; i < graph[from].size(); i++) {
                to = graph[from][i].first;
                int w = graph[from][i].second;
                if (costs[to] < costs[from] + w) {
                    costs[to] = costs[from] + w;
                    q.push(to);
                }
            }
        }


        // 리프 노드가 여러 개일 수 있으므로 비용이 최대인 노드 찾기
        int max = 0;
        for (int i = 0; i < leafs.size(); i++) {
            if (max < costs[leafs[i]]) {
                max = costs[leafs[i]];
            }
        }
        cout << max << '\n';
    }
}
