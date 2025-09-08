#include <stdio.h>
// A와 B의 길이가 다르면, 짧은 것이 먼저 온다.
// 만약 서로 길이가 같다면, A의 모든 자리수의 합과 B의 모든 자리수의 합을 비교해서 작은 합을 가지는 것이 먼저온다. (숫자인 것만 더한다)
// 만약 1,2번 둘 조건으로도 비교할 수 없으면, 사전순으로 비교한다. 숫자가 알파벳보다 사전순으로 작다.

// 같으면 0, i번째가 j번째보다 작으면 -1, 크면 1
int compare(char str[][51], int i, int j) {
    int l1 = 0, l2 = 0, s1 = 0, s2 = 0, res = 0;
    while(str[i][l1] || str[j][l2]) {
        char c1 = str[i][l1], c2 = str[j][l2];
        if (c1) {
            if ('0' <= c1 && c1 <= '9') {
                s1 += c1 - '0';
            }
            l1++;
        }
        if (c2) {
            if ('0' <= c2 && c2 <= '9') {
                s2 += c2 - '0';
            }
            l2++;
        }
        if (res == 0) {
            res = c1 == c2 ? 0 : (c1 < c2 ? -1 : 1);
        }
    }
    if (l1 == l2) {
        if (s1 == s2) {
             return res;
        }
        return s1 < s2 ? -1 : 1;
    }
    return l1 < l2 ? -1 : 1;
}
int main() {
    int N;
    scanf("%d", &N);
    char str[51][51];
    int indexes[51];
    for (int i=0;i<N;i++) {
        scanf("%s", str[i]);
        indexes[i] = i;
    }
    for (int i=0; i < N;i++) {
        int k = i;
        for (int j=i+1;j<N;j++) {
            if (compare(str, indexes[k], indexes[j]) > 0) {
                k = j;
            }
        }
        int t = indexes[k];
        indexes[k] = indexes[i];
        indexes[i] = t;
    }
    for (int i=0;i<N;i++) {
        printf("%s\n", str[indexes[i]]);
    }
}