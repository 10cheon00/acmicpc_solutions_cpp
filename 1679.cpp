/*

dp[n] = N번째 수를 만들 때 사용한 수의 개수
1과 K가 주어지므로, min(dp[n-k] + 1,dp[n-1]+1) 이 dp[n]이 되고, dp[n]이 5보다 크면 실패
K가 6보다 큰 경우.. 6을 못만드므로 짝순이 패
 */


#include <iostream>
using namespace std;
int main() {
    int N, K;
    int dp[100000];
    int arr[1000];

    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }
    cin >> K;

    dp[0] = 0;
    int i=1;
    while (1) {
        dp[i] = dp[i-1] + 1;
        for (int j=0;j<N;j++) {
            if (i - arr[j] >= 0) {
                dp[i] = min(dp[i-arr[j]] + 1, dp[i]);
            }
        }
        if (dp[i] > K) {
            if (i%2) {
                cout << "jjaksoon win at " << i;
            } else {
                cout << "holsoon win at " << i;
            }
            return 0;
        }
        i++;
    }

}
