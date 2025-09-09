/*
k번째 순열 찾기
n=5 k=34
34 =    24*1 +    (2####)
        6*1 +     (23###)
        2*2 +     (235##)
        1*0       (2351#)
---
35142
24*2 +
6*3 +
2*0 +
1*1

20 2 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
 */
#include <iostream>
using namespace std;

long long int fact(int N) {
    long long int res = 1;
    for (int i = 1; i <= N; i++) {
        res *= i;
    }
    return res;
}

void solution1(int N, long long int K) {
    K--;
    int check[21], l = 0;
    for (int i = 1; i <= N; i++) {
        check[i] = 1;
    }
    long long int L = fact(N - 1);
    int res[20];
    for (int i = N - 1; i >= 0; i > 0 ? (L /= i--) : i--) {
        int cnt = L > 0 ? K / L : 0;
        int j = 1;
        while (j <= N) {
            if (check[j]) {
                if (cnt-- == 0) {
                    check[j] = 0;
                    break;
                }
            }
            j++;
        }
        res[l++] = j;
        if (L > 0) {
            K %= L;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << res[i] << ' ';
    }
}

void solution2(int N) {
    long long int K, res = 1;
    int arr[20];
    int check[21];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        check[i + 1] = 1;
    }
    K = fact(N - 1);
    int l = 0;
    for (int i = N - 1; i >= 1; K /= i--) {
        int cnt = 0;
        check[arr[l]] = 0;
        for (int j = 1; j < arr[l]; j++) {
            cnt += check[j];
        }
        res += K * cnt;
        l++;
    }
    cout << res;
}

int main() {
    int N, M;
    cin >> N >> M;
    if (M == 1) { // k번째 순열 찾기
        long long int K;
        cin >> K;
        solution1(N, K);
        // for (int K=fact(N-1); K<=fact(N); K++) {
        //     cout << K << ' ';
        //     solution1(N, K);
        //     cout << '\n';
        // }
    } else { // 순열의 위치 찾기
        solution2(N);
    }
}
