/*
- 도로(=튜플)
도로는 노드 하나를 의미
- 집합
경로간 우선순위에 따라 내림차순으로 정렬된 것
- 우선순위
ai != bi를 만족하는 가장 작은 i에 대해서 ai < bi면 (a...) < (b...) 이 때 더 작은 값을 갖는 경로가 더 높은 우선순위를 가짐
- 집합간 우선순위
두 집합을 튜플(경로)로 나타냈을 때의 우선순위를 따른다... 집합의 원소에 대한 우선순위를 고를 때 튜플로 비교하는 공식을 사용(어차피 집합 크기가 M인 것만 따지므로 비교 가능)
그러한 집합중에 우선순위가 가장 높은 집합을 찾고, 그 집합이 가진 경로의 끝점 정보 출력
집합을 찾는다기보다, 우선순위가 가장 높은 도로만 선택하면 된다. = 최소 신장 트리
5 4
NYYYY
YNYYY
YYNYY
YYYNY
YYYYN
*/
#include <iostream>
#include <vector>
using namespace std;

int N, M;

typedef struct {
    int s, e;
} Tuple;

vector<Tuple> tuples, result;
bool used[5000];

int parent[50];

int find(int x) {
    if (parent[x] == x) {
        return parent[x];
    }
    return parent[x] = find(parent[x]);
}

void union_(int x, int y) {
    x = find(x);
    y = find(y);
    if (x < y) {
        parent[y] = x;
    } else {
        parent[x] = y;
    }
}

bool isSameParent(int x, int y) {
    return find(x) == find(y);
}

void kruskal() {
    // 여기서 고른 노드들이 모든 정점을 연결하지만, 정확히 M개를 고르지는 않는다.
    // 연결된 그래프를 먼저 만들고, 최소 비용을 가진 노드를 추가하기.
    for (int i = 0; i < 50; i++) {
        parent[i] = i;
    }
    int i = 0;
    for (auto t = tuples.begin(); t != tuples.end(); ++t) {
        if (!isSameParent(t->s, t->e)) {
            union_(t->s, t->e);
            result.emplace_back(*t);
            M--;
            used[i] = true;
        } else {
            used[i] = false;
        }
        i++;
    }
}

int main() {
    cin >> N >> M;
    char ch;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> ch;
            if (ch == 'Y' && i < j) {
                tuples.emplace_back((Tuple){i, j});
            }
        }
    }

    kruskal();
    // 정답이 없는 경우는 최소 신장 그래프가 완성되지 않았을 때, 정확히 M개의 도로를 고르지 않았을 때
    // 최소 신장 그래프가 완성되지 않았다면, M개의 도로를 고르더라도 집합이 되지 않음
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        cnt += parent[i] == i;
    }
    if (cnt > 1) {
        cout << -1;
        return 0;
    }
    // 나머지 후보에서 정확히 M개의 도로를 선택할 수 있는지 체크
    int i = 0;
    while (M > 0 && i < tuples.size()) {
        if (!used[i]) {
            M--;
            result.emplace_back(tuples[i]);
        }
        i++;
    }
    if (M > 0) {
        cout << -1;
        return 0;
    }

    // for (auto t = result.begin(); t != result.end(); ++t) {
    //     cout << t->s << ' ' << t->e << '\n';
    // }
    for (int i = 0; i < N; i++) {
        parent[i] = 0;
    }
    for (auto t = result.begin(); t != result.end(); ++t) {
        parent[t->s]++;
        parent[t->e]++;
    }
    for (int i = 0; i < N; i++) {
        cout << parent[i] << ' ';
    }
}
