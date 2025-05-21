/*
출력 : 정답의 개수가 가장 적게 되도록 만드는 문자들, 정답의 개수가 가장 많게 되도록 만드는 문자들
ABZ
ZBA
BBB
---
CDEFGHBBB
#
없는 문자가 포함된 단어라면 건너뛰기
문자가 있더라도 개수가 부족해 만들 수 없는 단어라면 건너뛰기

*/
#include <iostream>
using namespace std;
char words[200001][10]={0};
int N = 0;

void solve(char boards[11]) {
    int b[26] = {0}, r[26]={0};
    for (int i = 0; boards[i]; i++) {
        b[boards[i] - 'A']++;
    }
    for (int i = 0; i < N; i++) {
        // 보드판에 없는 문자 사용 또는 가능한 문자 수보다 더 많이 사용 체크
        bool invalid = false;
        int w[26] = {0};
        for (int j = 0; words[i][j]; j++) {
            char c = words[i][j] - 'A';
            if (b[c] < ++w[c]) {
                invalid = true;
                break;
            }
        }
        if (invalid) {
            continue;
        }
        // 각 문자당 단 한 개만 추가
        bool added[26] = {false};
        for (int j = 0; words[i][j]; j++) {
            char c = words[i][j] - 'A';
            if (!added[c]) {
                added[c] = true;
                r[c]++;
            }
        }
    }

    // 최대 최소 찾기
    int max = 0, min = 200000;
    for (int i = 0; i < 26; i++) {
        if (b[i]) {
            min = min > r[i] ? r[i] : min;
            max = max < r[i] ? r[i] : max;
        }
    }

    // 출력
    for (int i = 0; i < 26; i++) {
        if (b[i] && r[i] == min) {
            cout << (char) (i + 'A');
        }
    }
    cout << ' ' << min << ' ';

    for (int i = 0; i < 26; i++) {
        if (b[i] && r[i] == max) {
            cout << (char) (i + 'A');
        }
    }
    cout << ' ' << max << '\n';
}

void input_with_solve() {
    while (1) {
        cin >> words[N];
        if (words[N][0] == '-') {
            break;
        }
        N++;
    }
    while (1) {
        char boards[11];
        cin >> boards;
        if (boards[0] == '#') {
            break;
        }
        solve(boards);
    }
}

int main() {
    input_with_solve();
}
