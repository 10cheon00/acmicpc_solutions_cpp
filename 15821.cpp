#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;

LL dist(LL x1, LL y1, LL x2, LL y2) {
    LL dx = x1 - x2, dy = y1 - y2;
    return dx * dx + dy * dy;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, K, P;
    vector<LL> arr;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> P;
        int x, y;
        LL maxd = 0;
        for (int j = 0; j < P; j++) {
            cin >> x >> y;
            LL d = dist(0, 0, x, y);
            if (maxd < d) {
                maxd = d;
            }
        }
        arr.emplace_back(maxd);
    }
    // 낚시터를 포함하려면 가장 먼 거리에 있는 점을 포함해야함.
    // 도형에서 가장 원점으로부터 먼 거리에 있는 점만 배열에 담고,
    // 이 배열을 정렬하여 K번째거리를 출력하면 될까?
    // N=100000
    // NlogN = 100000 * 17 * 20
    sort(arr.begin(), arr.end());
    cout << fixed;
    cout.precision(2);
    cout << (double)arr[K-1];
    // printf("%.2f", (double) arr[K - 1]);
}
