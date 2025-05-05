/*
약속 시간을 늦추거나, 당길 수 있음 = T가 무조건 양수는 아니다.
T가 커지거나 작아지면서 거리 계산을 할 때 전체의 절반 이상에 감소 영향을 미친다면..
A-B를 계산하고 정렬한 다음 가운데 위치에 있는 값들의 차를 계산하면 된다.
N이 홀수면 차가 없으니까 1개만 답이 되고,
N이 짝수면 차가 있으니까 계산하되, n1부터 n2까지의 정수 개수는 abs(n2-n1)+1이다.
4
1 10 9
2 10 8
3 10 7
4 10 6

4
1 10 9
2 8 6
3 6 3
4 5 1
3
10 13 -3
11 15 -4
30 34 4
4
10 14 -4
20 24 -4
30 39 -9
40 37 3
*/
#include <iostream>
#include <algorithm>
using namespace std;
int N;
int abs(int a) {
    return a > 0 ? a : -a;
}

int main() {
    cin >> N;
    int arr[50];
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        arr[i] = a - b;
    }
    sort(arr, arr + N);
    if (N % 2 == 1) {
        cout << 1;
        return 0;
    }
    cout << abs(arr[N/2] - arr[N/2-1]) + 1;
}
