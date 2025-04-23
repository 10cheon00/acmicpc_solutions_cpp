#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int search(vector<pair<int, int>> graph[], int F, int T) {
    queue<pair<int, int>> queue;
    bool visited[1001] = {false};
    int W = 0;
    queue.emplace(F, W);
    while (!queue.empty()) {
        F = queue.front().first;
        W = queue.front().second;
        queue.pop();
        if (F == T) {
            return W;
        }
        for (int i=0; i<graph[F].size(); i++) {
            int t = graph[F].at(i).first;
            int w = graph[F].at(i).second;
            if (!visited[t]) {
                visited[t] = true;
                queue.emplace(t, W + w);
            }
        }
    }
    return 0;
}

int main() {
    int N, M, F, T, W;
    vector<pair<int, int> > graph[1001];
    cin >> N >> M;
    for (int i = 1; i < N; i++) {
        cin >> F >> T >> W;
        graph[F].emplace_back(T, W);
        graph[T].emplace_back(F, W);
    }
    for (int i = 0; i < M; i++) {
        cin >> F >> T;
        cout << search(graph, F, T) << '\n';
    }
}
