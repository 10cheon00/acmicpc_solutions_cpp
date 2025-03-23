/*
주어진 수와 비슷한 수를 만들 수 있는가.
5542 | 4
5539+++
주어진 수에서 1을 빼보고 고장난 버튼이 없는 수까지 반복, 또는 1을 더해서 반복
만약 주어진 수를 1씩 빼서 만드는 것이 100에서 1을 더하거나 빼는 경우보다 오래걸릴 수 있다.
 */
#include <iostream>
using namespace std;

bool valid(int N, int e, bool allowed[]) {
    N += e;
    if (N == 0) {
        return allowed[0];
    }
    while (N) {
        if (!allowed[N % 10]) {
            return false;
        }
        N /= 10;
    }
    return true;
}

int nSize(int N) {
    if (N == 0) {
        return 1;
    }
    int cnt = 0;
    while (N) {
        cnt++;
        N /= 10;
    }
    return cnt;
}

int abs(int x) {
    return x > 0 ? x : -x;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M, t, i = 0, res = ~(1 << 31);
    bool allowed[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    cin >> N >> M;
    for (int j = 0; j < M; j++) {
        cin >> t;
        allowed[t] = false;
    }
    while (1) {
        if (N - i == 100 || i - N == 100) {
            // i를 더하거나 뺄 때 100을 지나치는 경우에는 뺀 횟수를 예상 결과로 만들고 탈출
            res = i;
            break;
        }
        if (N - i >= 0 && valid(N, -i, allowed)) {
            res = i + nSize(N - i);
            break;
        }
        if (valid(N, i, allowed)) {
            res = i + nSize(N + i);
            break;
        }
        i++;
    }
    // 직접 +-로 이동하는 경우가 더 빠르다면 갱신
    res = abs(100 - N) > res ? res : abs(100 - N);
    res = abs(N - 100) > res ? res : abs(N - 100);
    cout << res;
}
