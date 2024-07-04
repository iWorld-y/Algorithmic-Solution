#include <stdio.h>
#include <string.h>

void generateNextArray(const char *pattern, int *next) {
    int len = strlen(pattern);
    int i = 0, j = -1;
    next[0] = -1;
    while (i < len) {
        if (j == -1 || pattern[i] == pattern[j]) {
            i++;
            j++;
            // 修改原来的生成next数组的逻辑，避免重复计算
            if (pattern[i] != pattern[j])
                next[i] = j;
            else
                next[i] = next[j];
        } else {
            j = next[j];
        }
    }
    for (int i = 0; i < len; i++) {
        printf("%d\t", next[i]);
    }
    printf("\n");
}

int kmpSearch(const char *text, const char *pattern) {
    int textLen = strlen(text);
    int patternLen = strlen(pattern);
    int i = 0, j = 0;
    int next[patternLen];

    generateNextArray(pattern, next);

    while (i < textLen) {
        if (j == -1 || text[i] == pattern[j]) {
            i++;
            j++;
            if (j == patternLen) {
                // 匹配成功，返回在文本中的起始位置
                return i - j;
            }
        } else {
            j = next[j];
        }
    }

    // 未找到匹配，返回-1
    return -1;
}

int main() {
    char text[] = "abaaaabaabaaaaab";
    char pattern[] = "aaaaab";

    int index = kmpSearch(text, pattern);

    if (index != -1) {
        printf("Pattern found at index %d\n", index);
    } else {
        printf("Pattern not found\n");
    }

    return 0;
}