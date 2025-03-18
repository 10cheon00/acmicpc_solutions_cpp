/*
dfa는 맞는 패턴을 가진 문자열을 탐색하는 알고리즘
0번째는 초기 상태, 10011111이 진행되는 5번째와 6번째 상태일 경우에만,
  패턴이 일치하는 것으로 판별하고 나머지 상태의 경우는 불일치
    s  0| 1  0  0+ 1  1+ 0
    ----+-----------------
    0  1| 2  3  4  5  6  7
 0  1  !| 3  4  4  1  7  4
 1  2  0| !  !  5  6  6  0

 100101 -> 1001 + 01
 100110?
 -> 1001100 1001+100
    1001101 10011+01
 */

#include <iostream>
#include <cstring>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    int dfa[2][201] = {
        {1, 8, 3, 4, 4, 1, 7, 4, 8},
        {2, 0, 8, 8, 5, 6, 6, 0, 8}
    };
    while (t-- > 0) {
        char str[202];
        cin >> str + 1;

        int i = 0, len = strlen(str + 1), s = 0;
        for (i = 1; i <= len; i++) {
            s = dfa[str[i] - '0'][s];
        }
        // cout << "S : " << s << '|';
        if (s == 5 || s == 6 || s == 0) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << '\n';
    }
}
