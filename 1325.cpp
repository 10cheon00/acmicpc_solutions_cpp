#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N, M, A, B;
    cin >> N >> M;
    vector<int> graph[N + 1];
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        graph[B].push_back(A);
    }
    vector<int> list;
    queue<int> q;
    bool visited[N + 1];
    for (int i = 1; i <= N; i++) {
        int cnt = 1;
        memset(visited, 0, sizeof(bool) * (N + 1));
        visited[i] = true;
        q.emplace(i);
        while (!q.empty()) {
            int from = q.front();
            q.pop();
            for (int to: graph[from]) {
                if (visited[to]) {
                    continue;
                }
                cnt++;
                visited[to] = true;
                q.emplace(to);
            }
        }
        list.emplace_back(cnt);
    }
    int max = list[0];
    for (int i=0;i<list.size();i++) {
        if (max < list[i]) {
            max = list[i];
        }
    }
    for (int i=0;i<list.size();i++) {
        if (max == list[i]) {
            cout << i+1 << ' ';
        }
    }
}
