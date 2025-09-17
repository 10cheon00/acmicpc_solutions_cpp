#include <iostream>

using namespace std;

int main() {
    int N;
    int arr[101][101];
    long long dp[101][101];
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i=0;i<=N;i++) {
        dp[i][0] = dp[0][i] = 0;
    }

    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            dp[i][j] = 0;
            dp[1][1] = 1;
            // 왼쪽에서 오는 경우 계산
            for (int k=1;k<j;k++) {
                if (arr[i][k] + k == j) {
                    dp[i][j] += dp[i][k];
                }
            }
            // 위에서 오는 경우 계산
            for (int k=1;k<i;k++) {
                if (arr[k][j] + k == i) {
                    dp[i][j] += dp[k][j];
                }
            }
        }
    }

    cout << dp[N][N];
}
