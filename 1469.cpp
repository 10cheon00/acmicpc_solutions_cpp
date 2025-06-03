/*
최대한 오른쪽에 더 높은 숫자를 넣는 방법을 선택
불가능한 경우도 있음 dfs탐색?
16
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
4 5 1 2 1 4 2 5 8 10 11 12 13 15 16 14 6 8 9 7 10 3 11 6 12 3 13 7 9 15 14 16
??
3
1 2 3
231213
 */
#include <algorithm>
#include <iostream>
using namespace std;
int X[16], arr[33], N;

void print() {
    for (int i = 1; i <= 2 * N; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

// 주어진 수를 어디에 넣을지 고민하는게 아니라, 주어진 자리에 어떤 수를 넣을지 고민
bool dfs() {
    int k = 0;
    while (arr[++k] != -1)
        ;
    if (k > 2 * N) {
        for (int i = 1; i <= 2 * N; i++) {
            if (arr[i] == -1) {
                return false;
            }
        }
        return true;
    }
    for (int i = 0; i < N; i++) {
        int n = X[i];
        if (n != -1 && k + n + 1 <= 2 * N && arr[k] == -1 && arr[k + n + 1] == -1) {
            arr[k] = arr[k + n + 1] = n;
            X[i] = -1;
            // print(arr);
            if (dfs()) {
                return true;
            }
            arr[k] = arr[k + n + 1] = -1;
            X[i] = n;
        }
    }
    return false;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }
    sort(X, X + N);
    for (int i = 0; i <= 2 * N; i++) {
        arr[i] = -1;
    }
    if (dfs()) {
        print();
        return 0;
    }
    cout << -1;
}
