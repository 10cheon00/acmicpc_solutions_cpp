/*
답지를 보고 풀었음
i 위치에 있다면, dp[i]는 i까지 오는 최소 경로라는 전제, dp[D]가 답이 됨
기본적으로 1칸 이동 시 1만큼 비용이 늘어나니까, dp[i] = dp[i-1]+1
현재 위치까지 오는 지름길이 있다면 dp[s] + d = dp[i]가 되고,
 이미 구해놓았던 dp[i]랑 최소값 비교해야함
 */

#include <iostream>
using namespace std;
typedef struct {
    int s, e, d;
} Route;

Route routes[13];
int N, D;

int main() {
    cin >> N >> D;

    int dp[10001];
    for (int i = 1; i <= N; i++) {
        cin >> routes[i].s >> routes[i].e >> routes[i].d;
    }

    dp[0] = 0;
    for (int i = 1; i <= 10000; i++) {
        dp[i] = dp[i - 1] + 1;
        for (int j = 1; j <= N; j++) {
            if (i == routes[j].e) {
                dp[i] = min(dp[i], dp[routes[j].s] + routes[j].d);
            }
        }
    }
    cout << dp[D];
}
