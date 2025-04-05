/*
5
4 3 5 7 9
5개를 이으려면 최대 4개가 필요하다. 그런데 3개가 엮인 체인을 다 풀어버리면 전체 개수가 4개이므로, 3개만 써도 된다
3 4 5 7 9
^|-------
9
1 1 1 9 9 9 9 9 9
^^^^^^^|---------
이런 경우에는 1,1,1은 고리를 끊었을 때 전체 개수에서 빠지므로, 이런 것들을 우선해서 골라야 한다.
그냥 낮은 것부터 더하면서...?
s=12
k=4
n=9
n-k+1=6

1 2 3 9 9 9 9 9
s=6
k=3
n=8
n-k=5
n-k+1=6
s-1=5
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, t;
    cin >> N;
    vector<int> list;
    for (int i = 0; i < N; i++) {
        cin >> t;
        list.push_back(t);
    }
    sort(list.begin(), list.end()); // 오름차순 정렬..
    int S = 0;
    for (int K = 1; K <= list.size(); K++) {
        S += list[K - 1];
        if (S == N - K - 1) {
            cout << S;
            return 0;
        } else if (S > N - K - 1) {
            cout << N - K;
            return 0;
        }
    }
}
