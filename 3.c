#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concatenate(char *base, const char *new_input) {
    size_t base_len = base ? strlen(base) : 0;
    size_t new_len = strlen(new_input);
    char *result = realloc(base, base_len + new_len + 1);
    if (result == NULL) {
        printf("Memory allocation failed.\n");
        free(base);
        return NULL;
    }
    strcpy(result + base_len, new_input);
    return result;
}

int main() {
    char *str1 = NULL;
    char *str2 = NULL;
    char buffer[100];
    char *combined = NULL;

    printf("Enter first string: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    str1 = malloc(strlen(buffer) + 1);
    if (!str1) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    strcpy(str1, buffer);

    printf("Enter second string: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    str2 = malloc(strlen(buffer) + 1);
    if (!str2) {
        printf("Memory allocation failed.\n");
        free(str1);
        return 1;
    }
    strcpy(str2, buffer);

    combined = concatenate(NULL, str1);
    combined = concatenate(combined, str2);

    while (1) {
        printf("Enter another string (or Q to quit): ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strcmp(buffer, "Q") == 0) break;
        combined = concatenate(combined, buffer);
        if (!combined) break;
    }

    printf("\nOriginal strings:\n");
    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);
    printf("Concatenated result: %s\n", combined);

    free(str1);
    free(str2);
    free(combined);
    return 0;
}
