// 각 파티(집합)별로 진실을 아는 파티원이 있는 파티와 연결되어 있는지
// 판단해야함.

#include <iostream>
using namespace std;

int parent[51];
int n, m;

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void union_(int x, int y) {
    x = find(x);
    y = find(y);
    parent[y] = x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    // 진실을 아는 사람들 union
    int a, b, head;
    cin >> a;
    if (a > 0) {
        cin >> head;
    }
    for (int i = 1; i < a; i++) {
        cin >> b;
        union_(head, b);
    }

    // 각 파티별로 union
    int party[50][51];
    for (int i = 0; i < m; i++) {
        cin >> a;
        party[i][0] = a;
        if (a > 0) {
            cin >> party[i][1];
        }
        for (int j = 2; j <= a; j++) {
            cin >> party[i][j];
            union_(party[i][1], party[i][j]);
        }
    }

    // 집합들이 서로 아는지 판단
    int res = 0;
    for (int i = 0; i < m; i++) {
        if (find(party[i][1]) != find(head)) {
            res++;
        }
    }
    cout << res;
}