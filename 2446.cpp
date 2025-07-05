#include <stdio.h>
#define ABS(X) ((X) > 0 ? (X) : -(X))
int main() {
    int N;
    scanf("%d", &N);
    for (int y = 1 - N; y < N; y++) {
        for (int x = 1 - N; x <= ABS(y); x++) {
            if (x < -ABS(y)) {
                printf(" ");
            } else {
                printf("*");
            }
        }
        if (y + 1 < N) {
            puts("");
        }
    }
}
