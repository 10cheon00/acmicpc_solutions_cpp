#include <iostream>
#include <queue>
#include <vector>

#define INF ~(1<<31)
using namespace std;

typedef pair<int, int> P;

int n;
int dist[1001];
int rdist[1001];
vector<P> graph[1001];
vector<P> rgraph[1001];

void dijkstra(int s, int *dist, vector<P> *graph) {
    priority_queue<P> pq;

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[s] = 0;

    pq.push(P(s, 0));
    while (!pq.empty()) {
        int from = pq.top().first;
        int fromW = -pq.top().second;
        pq.pop();
        // 가중치가 가장 작은 정점을 시작점으로 하는 모든 노드를 조사,
        // 현재 정점의 가중치 + 노드의 가중치가 도착점의 가중치보다 작을 경우 갱신, 그 노드를 pq에 추가
        for (int i = 0; i < graph[from].size(); i++) {
            int to = graph[from][i].first, cost = fromW + graph[from][i].second;
            if (cost < dist[to]) {
                dist[to] = cost;
                pq.push(make_pair(to, -cost));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, x;
    cin >> n >> m >> x;

    int from, to, weight, max_cost = 0;
    for (int i = 0; i < m; i++) {
        cin >> from >> to >> weight;
        graph[from].push_back(make_pair(to, weight));
        rgraph[to].push_back(make_pair(from, weight));
    }

    // 모든 학생들은 자기 번호를 시작 위치로 하고, x로 가야한다.(x에서 리버스 그래프로 다익스트라)
    dijkstra(x, dist, graph);

    // x로 간 학생들은 다시 자기 번호로 돌아와야 한다.(x에서 다익스트라)
    dijkstra(x, rdist, rgraph);
    for (int i = 1; i <= n; i++) {
        if (dist[i] + rdist[i] > max_cost) {
            max_cost = dist[i] + rdist[i];
        }
    }
    cout << max_cost;
}
