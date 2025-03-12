// 주어진 배열의 중앙값은 우리가 구할 함수의 최소값의 x좌표였음.
// 함수 = f(x) = sum([abs(n - x) for n in arr])
// 경험적으로는 볼록함수가 됨(2차식형태로)
// 이유를 잘 모르겠지만 볼록함수의 최소는 중앙값에서 발견된다.
// 따라서 그냥 각 차원별로 정렬하고, 중앙값을 뽑으면 그만인데 리스트의 원소 수가 짝수라면,
//  두 개의 중앙값이 생기므로 더 작은 중앙값을 선택한다.(문제의 조건)
#include <iostream>
#include <algorithm>
#include <vector>
#define abs(X) ((X)>0?(X):-(X))

using namespace std;

int getDist(vector<int> &xx, int xm) {
    int sum = 0;
    for (auto iter = xx.begin(); iter != xx.end(); iter++) {
        sum += abs(*iter - xm);
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, x, y, i = 0;
    while (1) {
        vector<int> xx, yy;
        cin >> N;
        if (N == 0) {
            break;
        }

        for (int i = 0; i < N; i++) {
            cin >> x >> y;
            xx.push_back(x);
            yy.push_back(y);
        }
        sort(xx.begin(), xx.end());
        sort(yy.begin(), yy.end());
        int xm = xx[N / 2], ym = yy[N / 2];
        if (N % 2 == 0) {
            xm = xx[N / 2 - 1];
            ym = yy[N / 2 - 1];
        }
        cout << "Case "
                << ++i
                << ": (" << xm << "," << ym << ") "
                << getDist(xx, xm) + getDist(yy, ym) << '\n';
    }
}
