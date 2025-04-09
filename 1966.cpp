#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N;
    cin >> N;
    while (N-- > 0) {
        int M, L, t, cnt = 0;
        cin >> M >> L;
        priority_queue<int> pq; // <weight>
        queue<pair<int, bool> > q; // <w, 찾는 수>
        for (int i = 0; i < M; i++) {
            cin >> t;
            q.push(make_pair(t, i == L));
            pq.push(t);
        }
        while (!q.empty()) {
            if (q.front().first == pq.top()) {
                cnt++;
                if (q.front().second) {
                    break;
                }
                q.pop();
                pq.pop();
            } else {
                pair<int, int> iter = q.front();
                q.pop();
                q.push(iter);
            }
        }
        cout << cnt << '\n';
    }
}
