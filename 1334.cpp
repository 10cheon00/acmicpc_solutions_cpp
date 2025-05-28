/*
N은 최대 50자리 양의 정수.. 입력을 문자열로 받아야 한다.
1씩 더하면서 찾아볼 수 없음.
그냥 상위 절반 하위 절반을 비교하면 되지 않나?
12341234 -> 4321 > 1234 -> 12344321
12344321 -> 4321 = 4321 -> 12355321
12344444 -> 4321 < 4444 -> 12355321

 */
#include <iostream>
using namespace std;
int len, mid;
bool gte(char *s1, char *s2) {
    for (int i = 0; i < mid; i++) {
        if (s1[i] < s2[i]) {
            return true;
        }
        if (s1[i] > s2[i]) {
            return false;
        }
    }
    return s1[mid] <= s2[mid];
}
int main() {
    char str[100] = {0}, upper[100] = {0}, lower[100] = {0};
    cin >> str;
    len = -1;
    while (str[++len])
        ;
    mid = len / 2;
    if (len % 2) {
        for (int i = 0; i <= mid; i++) {
            upper[i] = str[mid - i];
            lower[i] = str[mid + i];
        }
    } else {
        for (int i = 0; i < mid; i++) {
            upper[i] = str[mid - i - 1];
            lower[i] = str[mid + i];
        }
    }
    if (gte(upper, lower)) { // upper <= lower
        int i = 0;
        upper[i]++;
        while (i < (len - 1) / 2) {
            if (upper[i] <= '9') {
                break;
            }
            upper[i] = '0';
            upper[++i]++;
        }
        if (i == (len - 1) / 2 && upper[i] > '9') {
            // 99..9
            cout << 1;
            for (int i = 0; i < len - 1; i++) {
                cout << 0;
            }
            cout << 1;
            return 0;
        }
    }
    for (int i = (len - 1) / 2; i >= len % 2; i--) {
        cout << upper[i];
    }
    cout << upper;
}
