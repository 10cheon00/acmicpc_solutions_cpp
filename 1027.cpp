/*
*
***** <?
***
**
****** <
***
**
****** <
**** <
**
***** <
*******  <--- 7
*** <
*
***** <

1. N개의 빌딩에 대해 보이는 고층 건물 조사 : N
2. 한 빌딩이 다른 N개의 빌딩들에 의해 가려지지 않는지 검사 : N
3. 2번의 빌딩들이 N개 존재 : N
O(N^3)?
N이 최대 50이므로, 50^3= 125000이니까 시간복잡도로는 문제가 없을것 같은데
기울기가 같은 빌딩은 가려진다고 판단.
*/
#include <iostream>
using namespace std;

double A(int dx, int dy) {
    if (dx == 0) {
        return ~(1 << 31);
    }
    return (double)dy / dx;
}

int main() {
    int n, h[50];
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    int buildings[50] = {0};
    for (int i = 0; i < n; i++) {
        double maxH = ~(1LL << 52);
        // 한쪽으로만 검사하면서 보이는 빌딩의 수를 누적
        // 검사할 때는 이전에 가장 높게 보였던 빌딩보다 더 높게 보여야 보이므로 기울기의 최대값 기억
        // N의 최대값이 50이므로 양옆으로 조사해도 되지만, 탐색한 빌딩들보다 높은 기울기를 가진 다음 빌딩은 무조건 보인다는 점을 이용해
        // O(N^2)으로 줄일 수 있다. 한쪽에서 보인다면 다른쪽에서도 무조건 보이는 것이 자명한 것도 있다.
        for (int j=i+1; j<n; j++) {
            double hh = A(j - i, h[j]-h[i]);
            if (hh > maxH) {
                buildings[i]++;
                buildings[j]++;
                maxH = hh;
            }
        }
    }
    int max = buildings[0];
    for (int i=0; i<n; i++) {
        max = max > buildings[i] ? max : buildings[i];
    }
    cout << max;
}
