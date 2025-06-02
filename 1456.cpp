/*
1<=A<=B<=100000000000000
소수의 N제곱꼴이면 거의 소수
최대 10^14이므로...
1 1000
2 4 8 16 32 64 128 256 512
3 9 27 81 243 729
5 25 125 625
7 49 343
11 121
13 169
17 ..
19 ..
23 ..
29 ..
31 ..
== 25
...
k번 제곱했을 때 범위를 벗어날때까지 반복?
 */
#include <iostream>
#include <set>
using namespace std;
typedef long long LL;

int main() {
    bool *not_prime = new bool[10000001];
    for (int i = 2; i < 10000000; i++) {
        if (not_prime[i]) {
            continue;
        }
        for (int j = 2 * i; j <= 10000000; j += i) {
            not_prime[j] = true;
        }
    }
    LL A, B, i = 2;
    cin >> A >> B;
    int cnt = 0;
    set<LL> s;
    while (1) {
        if (i * i > B) {
            break;
        }
        if (!not_prime[i]) {
            LL T = i;
            // long long 보다 커지게 되는 경우를 방지해야함
            while (T <= B / i) {
                T *= i;
                if (A <= T && s.find(T) == s.end()) {
                    s.emplace(T);
                    cnt++;
                }
            }
        }
        i++;
    }
    cout << cnt;
    delete not_prime;
    return 0;
}
