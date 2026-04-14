#include<stdio.h>
#include<string.h>

void xor_encript_decrypt(char data[], int key){
    int i;
    for(i=0; data[i] != '\0'; i++){
        data[i] = data[i] ^ key;
    }
}

int simple_checksum(char data[]){
    int i;
    int sum = 0;

    for(i = 0; data[i]!='\0'; i++){
        sum +=(unsigned char)data[i];
    }
    return sum;
}

void print_hex(char data[]){
    int i;
    for(i=0; data[i] != '\0';i++){
        printf("%02x ",(unsigned char)data[i]);
    }
    printf("\n");
}


int main(){
    char realID[] = "admin";
    char realPWD[] = "1234";

    char inputId[20];
    char inputPWD[20];

    char inputID[20];
    char inputPWD[20];

    char transferMSG[100] = "FROM=LeeDongHyeok|TO=Choseokhyun|AMOUNT=100,000";
    char encrypteMSG[100];
    char receivedMSG[100];
    char tamperedMSG[100];

    int key = 7;
    int checksum_before;
    int checksum_after;

    printf("========은행 보안 시나리오=========\n\n");

    printf("[1]인증\n");
    printf("id입력: ");
    scanf("%19s",inputPWD);

    printf("비밀번호 입력: ");
    scanf("%19s",inputPWD);

    if(strcmp(inputID,realID) != 0 ||strcmp(inputID,realID) != 0){
        printf("\n로그인 실패\n");
        printf("인증 실패로 거래를 중단합니다.\n");
        return 0;

    }

    printf("\n로그인 성공\n");
    printf("인증완료 사용자: %s\n\n",inputID);

    printf("[2]기밀성\n");
    printf("평문 전송 내용: %s\n",transferMSG);

    strcpy(encrypteMSG,transferMSG);
    xor_encript_decrypt(encrypteMSG,key);

    printf("암호화된 전송 내용(16진수): ");
    print_hex(encrypteMSG);
    printf("키가 없으면 원문 바로 읽기 어려움.\n\n");


    printf("[3]무결성\n");
    checksum_before = simple_checksum(encrypteMSG);
    printf("보내기 전 체크값: %d\n", checksum_before);

    strcpy(receivedMSG, encrypteMSG);
    checksum_after = simple_checksum(receivedMSG);
    printf("받은 후 체크값: %d\n", checksum_after);

    if(checksum_before == checksum_after){
        printf("무결성 확인 완료 -> 전송중 데이터 변환x\n");
    } else{
        printf("무결성 확인 실패 -> 데이터가 변경됨\n");
    }


    xor_encript_decrypt(receivedMSG,key);
    printf("복호화한 내용: %s\n\n",receivedMSG);

    printf("[4] 데이터 변조 예시\n");
    strcpy(tamperedMSG,encrypteMSG);
    tamperedMSG[5] = tamperedMSG[5] ^ 1;

    printf("변조된 데이터 체크값: %d\n",simple_checksum(tamperedMSG));
    if(checksum_before == simple_checksum(tamperedMSG)){
        printf("무결성 확인 성공");
    }else{
        printf("무결성 확인 샐패 -> 누군가 데이터 조작\n");
    }
    printf("\n");

    pritnf("[5]부인 방지");
    printf("거래 요청자 기록: %s\n", inputID);
    printf("은행은 로그인 기록 및 거래요청 했는지 조회 가능\n");
    return 0;




}