/*
가능한 개수 찾기
k*(L+1)<=C+1
그 개수가 13배수면 1빼기
남은 곡이 0이될때까지 반복...
*/
#include <iostream>
using namespace std;
int main() {
    int N, L, C;
    cin >> N >> L >> C;
    int cnt = 0, K = (C + 1) / (L + 1);
    if (K > N) {
        K = N;
    }
    if (K % 13 == 0) {
        K--;
    }
    while (N > K) {
        N -= K;
        cnt++;
    }
    cnt++;
    if (N % 13 == 0) {
        // K에 1만 빼도 될 때 = 1
        // K에 1을 뺐더니 13배수가 될 때 and K에 2를 뺐더니 초과될 때 = 2
        if ((K - 1) % 13 == 0 && N + 2 > K) {
            cnt++;
        }
    }
    cout << cnt;
}
