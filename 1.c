#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array[10];
    int cols[10];

    for (int i = 0; i < 10; i++) {
        int n;
        scanf("%d", &n);
        cols[i] = n;
        array[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            array[i][j] = i + 1;
        }
    }

    for (int i = 0; i < 10; i++) {
        printf("Row %d → ", i + 1);
        for (int j = 0; j < cols[i]; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 10; i++) {
        free(array[i]);
    }

    return 0;
}
