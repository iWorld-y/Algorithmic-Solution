#include <stdio.h>

void reverseString(char* s, int sSize) {
    char temp;
    for (int i = 0, j = sSize - 1; i < sSize / 2; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

int main() {

    return 0;
}
