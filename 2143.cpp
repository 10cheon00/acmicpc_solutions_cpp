/*
두 배열에서 부 배열을 골라 모든 원소의 값을 T로 만드는 조합의 종류
n=1000, m=1000
부 배열 = i, i+1, ... , j-1, j인 배열(연속적..)
부 배열 경우의 수 = 5050,
5050*5050?
*/
#include <iostream>
#include <unordered_map>
typedef long long LL;
using namespace std;

LL l1[1000], l2[1000];
unordered_map<LL, LL> A, B; // <sum, count>
int T, N, M;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> T >> N;
    for (int i = 0; i < N; i++) {
        cin >> l1[i];
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> l2[i];
    }

    // 주어진 배열에서 부 배열을 만들고 그 합을 key로 하여 맵에 갱신
    for (int len = 0; len < N; len++) {
        LL sum = 0;
        for (int j = 0; j <= len; j++) {
            sum += l1[j];
        }
        A[sum]++;
        for (int j = len + 1; j < N; j++) {
            sum = sum - l1[j - len - 1] + l1[j];
            A[sum]++;
        }
    }
    for (int len = 0; len < M; len++) {
        LL sum = 0;
        for (int j = 0; j <= len; j++) {
            sum += l2[j];
        }
        B[sum]++;
        for (int j = len + 1; j < M; j++) {
            sum = sum - l2[j - len - 1] + l2[j];
            B[sum]++;
        }
    }
    // A의 key와 B의 key를 합했을 때 T가 되는 count의 총 합 계산
    // 선형 탐색을 해버리면 시간 초과가 나버림
    LL res = 0;
    for (auto& pa : A) {
        auto pb = B.find(T - pa.first);
        if (pb != B.end()) {
            res += pa.second * pb->second;
        }
    }
    cout << res;
    return 0;
}
