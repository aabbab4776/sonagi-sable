#include <stdio.h>
#include <stdint.h>

uint32_t hash(const char *str) {
    uint32_t h = 2166136261u;

    while (*str) {
        h ^= (unsigned char)(*str);
        h *= 16777619u;
        str++;
    }

    return h;
}

int main() {
    char text[100];

    printf("평문 입력: ");
    scanf("%99s", text);

    uint32_t result = hash(text);

    printf("hash value: %u\n", result);
    printf("hash hex: %08x\n", result);

    return 0;
}