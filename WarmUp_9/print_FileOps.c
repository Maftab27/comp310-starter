#include <stdio.h>

int main() {
    const char* filename = "example.txt";

    FILE* fw = fopen(filename, "w");
    fprintf(fw, "Hello, World!");
    fclose(fw);

    FILE* fr = fopen(filename, "r");
    char line[256];
    while (fgets(line, sizeof(line), fr) != NULL) {
        printf("%s", line);
    }

    fclose(fr);

    return 0;
}