/*(i):
6 malloc calls

(ii)
Error checking should be added after each malloc call to ensure memory was successfully allocated

(iii)
The memory leak occurs because destroy_matrix only frees the outer pointer p, not the individual rows.

(iv)*/
int **create_matrix(int m, int n) {
    int **p = malloc(m * sizeof(int*));
    int *data = malloc(m * n * sizeof(int));
    for (int i = 0; i < m; ++i) {
        p[i] = data + i * n;
    }
    return p;
}
