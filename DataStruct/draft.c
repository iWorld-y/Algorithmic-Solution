#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    // qsort库要求参数const
    return strcmp((char*)a, (char*)b);
}

int firstUniqChar(char* s) {
    qsort(s, strlen(s), sizeof(char[0]), cmp);
    for (int i = 0; i < strlen(s); i++) printf("%c %d\n", s[i], i);
    printf("\n\n");
    printf("\n\n");
}

int main() {
    char* s = "leetcode";
    firstUniqChar(s);
    return 0;
}