/*
x와 d가 자연수일 때, 첫 k개의 항의 합이 [l,r]인 수의 개수
등차수열의 합
k/2 * (2x + (k-1)d)
2<=k<=5
2 = 3 4 5 6 ...
3 = 6 9 12 15 ...
4 = 10 14 16 18 ...
5 = 15 20 25 30 ...
 */

#include <iostream>
using namespace std;
int main() {
    int l, ll, r, k;
    int left[6] = {0, 0, 3, 6, 10, 15};
    int d[6] = {0, 0, 1, 3, 2, 5};
    cin >> l >> r >> k;
    ll = l > left[k] ? l : left[k];
    int res = r / d[k] - (ll - 1)/d[k];
    if (k == 4 && l <= 12 && 12 <= r) {
        res -= 1; // k=4일 때 12를 만들 수 없기 때문에 하나 빼기
    }
    cout << (res > 0 ? res : 0);
}
