#include <stdio.h>
#include <string.h>

void encrypt(unsigned char text[], int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = (text[i] + key) % 256;
    }
}

void decrypt(unsigned char text[], int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = (text[i] - key + 256) % 256;
    }
}

int main() {
    unsigned char text[100] = "HELLO";
    int key = 7;

    printf("원문: %s\n", text);

    encrypt(text, key);

    printf("암호문 숫자: ");
    for (int i = 0; text[i] != '\0'; i++) {
        printf("%d ", text[i]);
    }
    printf("\n");

    decrypt(text, key);

    printf("복호화: %s\n", text);

    return 0;
}