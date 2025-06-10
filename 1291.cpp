// 문제 지문이 너무 길어서 포기

#include <bits/stdc++.h>
using namespace std;

// 1) 자리수 합
int digit_sum(int n) {
    int s = 0;
    while (n) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

// 2) 이면수 판정
bool isImyeonsu(int n) {
    if (n <= 5) return false;
    if (digit_sum(n) % 2 == 0) return false;
    // n>=4 이면 2와 3의 합으로 표현 가능하므로 추가 검사 불필요
    return true;
}

// 3a) 소수 판정
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}

// 3b) 임현수 판정
bool isImhyunsu(int n) {
    if (n == 2 || n == 4) return true;
    if (n <= 1 || isPrime(n)) return false;

    int cnt = 0;
    int m = n;
    for (int p = 2; p * p <= m; ++p) {
        if (m % p == 0) {
            ++cnt;
            while (m % p == 0) m /= p;
        }
    }
    if (m > 1) ++cnt;

    return (cnt % 2 == 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    bool I = isImyeonsu(N);
    bool H = isImhyunsu(N);

    if (I && H)       cout << 4;
    else if (I)       cout << 1;
    else if (H)       cout << 2;
    else              cout << 3;

    return 0;
}
