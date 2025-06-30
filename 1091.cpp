/*
사이클을 나눈 후 나머지 정리를 통해 정확한 값을 구할 수 있겠지만...
N이 정해져 있어서 브루트 포스로 풀기로 했다.
섞는게 불가능한 경우는 그냥 백만번 돌렸을 때 답을 못구하면 -1을 출력하기로 했다.
 */
#include <iostream>
using namespace std;
int N, cnt = 0;
int S[48];
int P[48];

void shuffle_cards() {
    bool visited[48] = {false};
    for (int i=0;i<N;i++) {
        if (visited[i]) {
            continue;
        }
        int j = i, M, T = S[j];
        while (i != P[j]) {
            // 이동할 위치에 있는 수를 미리 꺼내기
            M = S[P[j]];
            // 이동시키기
            S[P[j]] = T;
            visited[P[j]] = true;
            // 다음에 삽입할 수를 미리 꺼낸 수로 정하기
            T = M;
            // 인덱스 업데이트
            j = P[j];
        }
        S[i] = T;
        visited[i] = true;
    }
    cnt++;
}

bool check() {
    for (int i=0;i<N; i++) {
        if (S[i] % 3 != i % 3) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    while (1) {
        if (check()) {
            cout << cnt;
            return 0;
        }
        if (cnt > 1000000) {
            cout << -1;
            return 0;
        }
        shuffle_cards();
    }
}
