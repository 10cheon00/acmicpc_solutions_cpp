#include <stdio.h>

int main() {
    int n = 5, t, sum = 0;
    while (n-- > 0) {
        scanf("%d", &t);
        sum += t * t;
    }
    printf("%d", sum % 10);
}
