#include <stdio.h>
#define ABS(X) ((X) > 0 ? (X) : (-(X)))
int main() {
    int N;
    scanf("%d", &N);
    for (int y = 0; y < N; y++) {
        for (int x = 1 - N; x < N; x++) {
            if (y == ABS(x)) {
                printf("*");
                if (x > 0) {
                    break;
                }
            } else {
                printf(" ");
            }
        }
        if (y + 1 < N) {
            puts("");
        }
    }
}
