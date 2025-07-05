#include <stdio.h>
/*
밑변 길이
3 = 5
6 = 11
24 = 47
= 2*N-1
     *
    * *
   *****
  *     *
 * *   * *
***** *****
           *
          * *
         *****
        *  @  *
       * *   * *
      ***** *****
     *54321@     *
    *@*54  1    * *
   *****5  2   *****
  *  @  *  3  *  @  *
 *@*   *@* 4 * *   * *
***** *****5***** *****
중심으로부터 어느 구역에 있는지..?
가운데 구역에 있으면 공백, 그렇지 않다면 좌표에 따라 중심 다시 잡고 N-1
N이 3일 때 중심좌표가 아니면 별, 그렇지 않으면 공백
48 -> 12
24 -> 6
12 -> 3
6 -> 2
삼각형 외부에 있다면 무조건 공백
 */
int abs(int x) { return x > 0 ? x : -x; }
char fractal(int y, int x, int cx, int cy, int N) {
    if (N == 3) {
        return cx == x && cy == y ? ' ' : '*';
    }
    // 위쪽 구역이라면 위로 보내기
    if (y < cy) {
        if (N == 6) {
            cy -= 2;
        } else {
            cy -= N / 4;
        }
        return fractal(y, x, cx, cy, N / 2);
    }
    int dist = abs(cx - x) + y - cy;
    if (dist < N / 2) {
        return ' ';
    }
    if (N == 6) {
        cy += 1;
    } else {
        cy += N / 4;
    }
    if (cx < x) {
        // 오른쪽
        cx += N / 2;
    } else {
        // 왼쪽
        cx -= N / 2;
    }
    return fractal(y, x, cx, cy, N / 2);
}

int main() {
    int N;
    scanf("%d", &N);
    int cx = N , cy = N / 2 + 1;
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x < 2 * N; x++) {
            if (abs(cx - x) / y >= 1) {
                printf(" ");
            } else {
                printf("%c", fractal(y, x, cx, cy, N));
            }
        }
        puts("");
    }
}
