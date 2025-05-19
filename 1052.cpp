/*
23 = 10111
13 = 1101
1 1 1 1 1 1 1 1  1 1 1 1  ___ 1
 2   2   2   2    2   2
   4       4        4
       8
13 2
1101
 101 + 011 = 1000
13 1
1101
ans: 3
N의 비트수 < K일 때만 찾기
11110100001001000000
11111000000000000000
      11110111000000
    0100001001000000
왼쪽부터 K-1개 비트는 제외
1024 3
ans: 2

 */
#include <iostream>
using namespace std;
int N, K;

int bits(int n) {
    int cnt = 0;
    while (n) {
        cnt += n&1;
        n >>= 1;
    }
    return cnt;
}

int solve() {
    if (N < K || bits(N) <= K) {
        return 0;
    }
    int M = 0, O = 0;
    while (bits(N) != K-1) {
        M |= (N&1) << O++;
        N >>= 1;
    }
    return (1 << O) - M;
}

int main() {
    cin >> N >> K;
    cout << solve();
}
