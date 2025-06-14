/*
3
3
111/3=39
문제는, int범위를 넘어가버리기 때문에 자리수만 출력한다
1(100)1이 답일수도있음
이런 수가 N으로 나눠지는지 확인하는 방법은? 어렵기 때문에 모듈러 연산 이용해야함
111 % 101 = 1...10
10 * 10 + 1 =>
1111 % 101 = 11...0
 */
#include <iostream>
using namespace std;
int main() {
    int N, K = 1, L = 1;
    cin >> N;
    // 불가능한 경우
    if (N%2==0 || N%5==0) {
        cout << -1;
        return 0;
    }
    while (1) {
        if (K % N == 0) {
            cout << L;
            return 0;
            // break;
        }
        L++;
        K = (K % N) * 10 + 1;
    }
}
