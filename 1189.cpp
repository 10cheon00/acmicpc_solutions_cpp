/*
 * 1189 �Ĺ�Ȩ
 * �ǹ�I
 */
#include <iostream>
char** arr;
int count = 0, R, C, K;

void check(int step, int x, int y) {
    if (step == K) {
        if (y == 0 && x == C - 1) {
            count++;
        }
        return;
    }
    arr[y][x] = '!';
    // ��
    if (0 < y) {
        if (arr[y - 1][x] == '.') {
            check(step + 1, x, y-1);
        }
    }
    // ��
    if (x + 1 < C) {
        if (arr[y][x + 1] == '.') {
            check(step + 1, x + 1, y);
        }
    }
    // ��
    if (0 < x) {
        if (arr[y][x - 1] == '.') {
            check(step + 1, x - 1, y);
        }
    }
    // ��
    if (y + 1 < R) {
        if (arr[y + 1][x] == '.') {
            check(step + 1, x, y + 1);
        }
    }
    arr[y][x] = '.';
}

int main() {
    scanf("%d %d %d", &R, &C, &K);
    arr = new char* [R];
    for (int i = 0; i < R; i++) {
        arr[i] = new char[C + 1];
        scanf("%s", arr[i]);
    }

    check(1, 0, R-1);
    printf("%d", count);
    for (int i = 0; i < R; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}