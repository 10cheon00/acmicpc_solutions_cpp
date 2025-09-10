#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int N, M;
    vector<int> list;
    unordered_set<int> pool;
    unordered_map<int, int> m;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M;
        list.emplace_back(M);
        if (m.find(M) == m.end()) {
            m[M] = 0;
        }
        m[M]++;
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int S = list[i] + list[j];
            auto it = m.find(S);
            if (it == m.end()) {
                continue;
            }
            int size = it->second - (S == list[i]) - (S == list[j]);
            if (size > 0) {
                pool.insert(S);
            }
        }
    }
    int cnt = 0;
    for (int n: list) {
        cnt += pool.find(n) != pool.end();
    }
    cout << cnt;
}
