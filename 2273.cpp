/*
주어지는 관계를 노드로 표현하고 A B로 주어질 때 B->A로 단방향 그래프 만들기
bfs로 탐색하되 depth를 인덱스로 하는 vector 배열에 추가
각 vector 배열의 사이즈가 곧 범위?

위상정렬을 수행한다면? 진입차수를 더하면 depth가 되긴한다.
위상정렬할수 없는 경우
1--2--3--4
5----/ \-6
6 5
1 2
2 3
3 4
5 3
3 6
위 그래프는 위상정렬이 152346순으로 된다.
이 경우는 1,2,5간의 크기비교가 안되지 않나?
ans
1 2
2 3
4 4
5 6
1 3
5 6
5의 위치가 정확히 특정되지 않으므로 1~3사이라고 하면 된다
---
자신보다 키가 작은 사람(a), 큰 사람(b)을 세고,
(a, N-b]을 범위로 제시하면 된다

 */
#include <iostream>
#include <queue>
#define INF 100000009
using namespace std;
int dist[257][257];
int rdist[257][257];
vector<int> graph[257];
vector<int> rgraph[257];
int N, M;

int min(int a, int b) {
    return a > b ? b : a;
}

void input() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dist[i][j] = i == j ? 0 : INF;
            rdist[i][j] = i == j ? 0 : INF;
        }
    }
    for (int i = 0; i < M; i++) {
        int f, t;
        cin >> f >> t;
        graph[f].emplace_back(t);
        rgraph[t].emplace_back(f);
        dist[t][f] = -1;
        rdist[f][t] = -1;
    }
}

void print() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (dist[i][j] == INF) {
                cout << "  ";
            } else {
                cout << dist[i][j] << ' ';
            }
        }
        cout << '\n';
    }
}

int main() {
    input();
    for (int k = 1; k <= N; k++) {
        for (int f = 1; f <= N; f++) {
            for (int t = 1; t <= N; t++) {
                if (dist[f][k] != INF && dist[k][t] != INF) {
                    dist[f][t] = min(dist[f][t], dist[f][k] + dist[k][t]);
                }
                if (rdist[f][k] != INF && rdist[k][t] != INF) {
                    rdist[f][t] = min(rdist[f][t], rdist[f][k] + rdist[k][t]);
                }
            }

            if (dist[f][f] < 0) {
                cout << -1;
                return 0;
            }
        }
    }

    for (int i=1; i<=N; i++) {
        int a=0, b=0;
        for (int j=1; j<=N; j++) {
            a += dist[i][j] < 0;
            b += rdist[i][j] < 0;
        }
        cout << a+1 << ' ' << N-b << '\n';;
    }
}
