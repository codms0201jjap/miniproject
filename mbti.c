#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PEOPLE 100

typedef struct{
	char mbti[MAX_PEOPLE]; //자신의 mbti
	char name[100]; //이름
	char department[12]; //학부
	int s_num; //학번
	char sex; //성별
} Mbti;

int selectMenu() {
    int menu;
    printf("\n*** mbti 결과 분석 서비스 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 저장\n");
    printf("6. 검색\n");
    printf("7. 분석\n");
    printf("8. mbti에 관한 정보\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int createMbti(Mbti *m){
	printf("이름은? ");
	scanf("%s", m->name);
	printf("성별은? ");
	scanf("%s", m->sex);
	printf("학부는? ");
	scanf("%s", m->department);
	printf("학번은? ");
	scanf("%d", &m->s_num);
	printf("MBTI는? ");
	scanf("%s", m->mbti);
	printf("=> 추가됨!\n");
	return 1;
}

void readMbit(Mbti m){
	printf("%s %d %s %s %s\n", m->name, m->s_num, m->sex, m->department, m->mbti);
}

void listMbti(Mbti *m[], int count){
    printf("\nNo Name Student_number Sex Department Mbti\n");
    printf("================================================\n");
    for(int i = 0; i < count; i++){
        printf("%-2d", i+1);
        readMbti(*m[i]);
    }
    printf("\n");
}
