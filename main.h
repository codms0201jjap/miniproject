#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char mbti[10];//mbti 결과
    char name[20];//이름
    char department[20];//학부
    char sex[10];//성별
    char s_id[15];//학번
} mbti_struct;

int createMbti(mbti_struct *s[], int number); // mbti 추가 함수 
int updateMbti(mbti_struct *s[], int number); // mbti 수정 함수 
int deleteMbti(mbti_struct *s[], int number); // mbti 삭제 함수 
int loadData(mbti_struct *s[]); // 데이터 로드 해오는 함수
void readMbti(mbti_struct *s[], int number);    // 전체 제품 출력 함수 (mbti 조회)
void saveMbti(mbti_struct *s[], int number);    // 파일 저장 함수 (mbti 저장)
void searchMbti1(mbti_struct *s[], int number);//검색 기능1(학부)
void searchMbti2(mbti_struct *s[], int number);//검색 기능2(학번)
void searchMbti3(mbti_struct *s[], int number);//검색 기능3(mbti별)
void searchMbti4(mbti_struct *s[], int number);//검색 기능4(이름)
int selectMenu();
void Clear(void);
