/*
abcde           = n개
a,b,c,d,e       = n
aa,ab ... ee    = n^2
aaa,aab, ... dbd, dbe = ??
    d의 위치 k, k*n^2 +
    b의 위치 l, l*n +
    e의 위치 m, m
= k*n^2 + l*n + m
= ((k*n + l)*n + m)*1
*/
#include <iostream>
#define MOD 900528
using namespace std;

int indexOf(char *str, char c) {
    int i = -1;
    while (str[++i] != c);
    return i + 1; // 1 base
}

int main() {
    char pool[101];
    char cipher[1000001];
    cin >> pool >> cipher;
    int N = -1, C = -1;
    while (pool[++N]);
    while (cipher[++C]);
    int result = indexOf(pool, cipher[0]);
    for (int i = 1; i < C; i++) {
        result = (result * N + indexOf(pool, cipher[i])) % MOD;
    }
    cout << result;
}
