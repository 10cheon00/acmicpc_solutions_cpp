#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int W(char c) {
    if (c == '0') {
        return 0;
    }
    if (c < 'a') {
        return c - 'A' + 27;
    }
    return c - 'a' + 1;
}

int main() {
    int N, total = 0;
    cin >> N;
    char str[51];
    vector<pair<int,int>> graph[51];
    for (int f=1; f<=N; f++) {
        cin >> str;
        for (int t=1; str[t-1]; t++) {
            int w = W(str[t-1]);
            total += w;
            if (f == t || w == 0) {
                continue;
            }
            graph[f].emplace_back(t, w);
            graph[t].emplace_back(f, w);
        }
    }

    // 모든 노드들이 최소 비용으로만 연결되어 있어야 함
    // 최소 신장 트리 구하기
    int len = 0;
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, 1);
    bool visited[51];
    while (!pq.empty()) {
        int w = -pq.top().first;
        int f = pq.top().second;
        pq.pop();
        if (visited[f]) {
            continue;
        }
        visited[f] = true;
        len += w;
        for (int i=0; i<graph[f].size(); i++) {
            pq.emplace(-graph[f][i].second, graph[f][i].first);
        }
    }
    // 모든 노드들이 연결되었는지 탐색...
    for (int i=1; i<=N; i++) {
        if (!visited[i]) {
            cout << -1;
            return 0;
        }
    }
    // 답 = 랜선 전체 길이 - 그래프의 전체 비용
    cout << total - len;
}
