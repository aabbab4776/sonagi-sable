#include<stdio.h>
#include<string.h>

void xor_with_key(char data[], char key[]){
    int i;
    int keyLen = strlen(key);

    for(i = 0; data[i]!='\0'; i++){
        data[i] = data[i] ^ key[i % keyLen];
    }
}

void print_hex(char data[]){
    int i;
    for(i = 0;data[i] != '\0';i++){
        printf("%02x ", (unsigned char)data[i]);
    }
    printf("\n");

}

int main(){
    char plainText[100]="DONGHYEOK_BANK";
    char key[20] ="key";
    char encrypted[100];
    char decrypted[100];

    printf("===평문, 암호화, 키의 관계===\n\n");

    printf("[1]평문\n");
    printf("평문:%s\n\n",plainText);

    printf("[2]키 \n");
    printf("사용할 키: %s\n\n", key);

    strcpy(encrypted, plainText);
    xor_with_key(encrypted, key);

    printf("[3]암호화\n");
    printf("암호화된 데이터: ");
    print_hex(encrypted);


    strcpy(decrypted, encrypted);;
    xor_with_key(decrypted, key);

    printf("[4]복호화\n");
    printf("같은 키로 다시 연산 한 결과: %s\n\n", decrypted);

    printf("[5]비교\n");
    printf("평문 전송: %s\n", plainText);
    printf("암호화 전송: ");
    print_hex(encrypted);

    printf("설명\n\n");
    printf("평문 + 키 -> 암호화 -> 암호문\n");
    printf("암호문 + 같은 키 -> 복호화 -> 평문");

    return 0;


    

}