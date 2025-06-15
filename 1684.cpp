/*
힌트를 보았다..
나머지가 같다. == 몫이 달라지면 언젠가 같은 수가 된다.
N-R = D * k
D가 고정된 길이이므로, 이 고정된 값인 D가 k개 모여서 N-R이 된다.
개수(k)는 중요하지 않고, 이러한 D(>=1)중에 제일 큰 값을 찾는 것.
만약 그렇게 고정된 값으로 N-R을 만들 수 있다면, D들이 모여서 N-R이 되므로 현재 각 숫자들의 차이 역시 D의 배수이다.
따라서 현재 각 숫자들의 차를 구해보면 D를 알 수 있다.
이 차이들의 최대공약수만이 D의 배수에서 D가 된다.
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
int main() {
    int N, n;
    cin >> N;
    vector<int> list, l2;
    for (int i = 0; i < N; i++) {
        cin >> n;
        list.emplace_back(n);
    }
    sort(list.begin(), list.end(), greater<int>());
    int res = list[0] - list[1];
    for (int i = 1; i < N - 1; i++) {
        res = gcd(res, list[i] - list[i + 1]);
    }
    cout << res;
}
