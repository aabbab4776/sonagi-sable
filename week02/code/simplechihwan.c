#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAX 200


void encrypt(char text[], char key[]){

    for(int i = 0; text[i] != '\0'; i++){
        char ch = text[i];
        
       if(ch >= 'A' && ch <= 'Z'){
        text[i] = key[ch - 'A'];
        
       } 
       else if(ch >= 'a' && ch <= 'z'){
        text[i] = tolower(key[ch - 'a']);
       }
   
    }



}
void decrypt(char text[], char key[]){

    for(int i = 0; text[i] != '\0'; i++){
        char ch = text[i];

        if(ch >= 'A' && ch <= 'Z'){
            for(int j = 0; j <26; j++){
                if(key[j] == ch){
                    text[i] = 'A' + j;
                    break;
                }
            }
        }
    }


}

int main(){

    char text[MAX];
    int choice;


    char key[27] ="QWERTYUIOPASDFGHJKLZXCVBNM";
    printf("============단순 치환 암호============\n");
    printf("1.암호화\n");
    printf("2.복호화\n");
    printf("선택: ");
    scnanf("%d", &choice);

    getchar();

    printf("문자열 입력: ");
    fgets(text, MAX, stdin);

    text[strspn(text,"\n")] = '\0';

    if(choice == 1){
        encrypt(text, key);
        printf("암호문 : %s\n", text);

    }
    else if(choice == 2){
        decrypt(text, key);
        printf("복호문 : %s\n", text);
    }
    else{
        printf("잘못된 선택입니다.\n");
    }
            

    return 0;

}