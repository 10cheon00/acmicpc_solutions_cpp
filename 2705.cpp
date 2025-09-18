/*
7 = 1111111
     3 1 3
    11311
     232
    151
    7
4 = 1111
    121
    22
    4
 */
#include <iostream>
using namespace std;
int dp[1001];
int solve(int T) {
    if (dp[T] != 0) {
        return dp[T];
    }
    dp[T] = 1;
    for (int N=1;N<=T/2;N++) {
        dp[T] += solve(N);
    }
    return dp[T];
}

int main() {
    int N, T;
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> T;
        cout << solve(T) << '\n';
    }
}