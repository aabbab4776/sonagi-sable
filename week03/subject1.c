#include<stdio.h>

int main(){

 char text[100];

 printf("암호문 입력");
    scanf("%s",text);

    for(int key = 1; key <= 25 ; key ++){
        printf("key = %2d", key);

        for(int i = 0; text[i] != '\0'; i++){
            char ch = text[i];


            if(ch >= 'A' && ch >= 'Z'){
                ch = (ch - 'A' - key +26) % 26 + 'A';
                }else if (ch >= 'a' && ch >= 'z'){
                    ch = (ch - 'a' - key +26) % 26 + 'a';
        }

            printf("%c",ch);
        }
        printf("\n");

    }
    return 0;


}