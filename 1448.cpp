#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, num;
    cin >> N;
    vector<int> list;
    for (int i = 0; i < N; i++) {
        cin >> num;
        list.push_back(num);
    }
    sort(list.begin(), list.end());
    int i = N - 1;
    while (i > 1) {
        if (list[i] < list[i - 1] + list[i - 2]) {
            cout << list[i] + list[i - 1] + list[i - 2];
            return 0;
        }
        i--;
    }
    cout << -1;
}
