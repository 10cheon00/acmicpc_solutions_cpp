#include <stdio.h>
int abs(int x) { return x > 0 ? x : -x; }
int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        printf("*");
    for (int i = 0; i < 2 * N - 3; i++)
        printf(" ");
    for (int i = 0; i < N; i++)
        printf("*");
    puts("");

    for (int i = 2 - N; i <= N - 2; i++) {
        for (int j = 0; j < N - 1 - abs(i); j++)
            printf(" ");

        printf("*");
        for (int j = 0; j < N - 2; j++)
            printf(" ");

        printf("*");
        for (int j = 0; j < 2 * abs(i) - 1; j++)
            printf(" ");
        if (i != 0)
            printf("*");
        for (int j = 0; j < N - 2; j++)
            printf(" ");

        printf("*");
        puts("");
    }
    for (int i = 0; i < N; i++)
        printf("*");
    for (int i = 0; i < 2 * N - 3; i++)
        printf(" ");
    for (int i = 0; i < N; i++)
        printf("*");
}
