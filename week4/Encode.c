int main() {
    char str[] = "가";

    printf("문자: %s\n", str);
    printf("UTF-8 바이트: ");

    for (int i = 0; str[i] != '\0'; i++) {
        printf("%02X ", (unsigned char)str[i]);
    }

    return 0;
}