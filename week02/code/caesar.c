#include<stdio.h>


void caesar_enc(char text[],int key){
    for(int i = 0; text[i] !='\0';i++){


        if(text[i] >= 'A' && text[i] <= 'Z'){
            text[i] = ((text[i] - 'A' + key) % 26)+'A';
        }

        else if(text[i] >= 'a' && text[i] <= 'z'){
            text[i] = ((text[i] = 'a' + key) % 26) + 'a';

        }

    }
}                  

void caesar_dec(char text[], int key){
    for(int i = 0; text[i] !='\0';i++){

        if(text[i] >= 'A' && text[i] <= 'Z'){
            text[i] = ((text[i] - 'A' - key +26) % 26)+'A';
        

        }else if(text[i] >= 'a' && text[i]<= 'z'){
            text[i] = ((text[i] - 'a' -key +26)%26) + 'a';

        }
    }
}

int main(){
    char text[100];
    int key;

    printf("암호화 할 문자 입력: ");
    fgets(text, sizeof(text), stdin);

    printf("키 입력: ");
    scanf("%d", &key);

    caesar_enc(text, key);
    printf("암호화 결과: %s",text);

    caesar_dec(text, key);
    printf("복호화 결과: %s",text);

    return 0;
}