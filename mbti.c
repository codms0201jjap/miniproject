#include "main.h"

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

int createMbti(mbti_struct *m){
        printf("이름은? ");
        scanf("%s", m->name);
        printf("성별은? ");
        scanf("%s", m->sex);
        printf("학부는? ");
        scanf("%s", m->department);
        printf("학번은? ");
        scanf("%s", &m->s_id);
        printf("MBTI는? ");
        scanf("%s", m->mbti);
        printf("=> 추가됨!\n");
        return 1;
}

void readMbti(mbti_struct m){
        printf("%s %s %s %s %s\n", m.name, m.s_id, m.sex, m.department, m.mbti);
}

void listMbti(mbti_struct *m[], int count){
    printf("\nNo Name Student_number Sex Department Mbti\n");
    printf("================================================\n");
    for(int i = 0; i < count; i++){
        printf("%-2d", i+1);
        readMbti(*m[i]);
    }
    printf("\n");
}

int updateMbti(mbti_struct *m){
        printf("이름은? ");
        scanf("%s", m->name);
        printf("성별은? ");
        scanf("%s", m->sex);
        printf("학부는? ");
        scanf("%s", m->department);
        printf("학번은? ");
        scanf("%s", &m->s_id);
        printf("MBTI는? ");
        scanf("%s", m->mbti);
        printf("=> 수정됨!\n");
        return 1;
}

void Clear(void)
{
    while (getchar() != '\n');
}

int deleteMbti(mbti_struct *s[], int number)
{
    int index;
    printf("삭제할 번호 (0 : 취소) : ");
    scanf("%d", &index);
    if (index == 0)
        return number - 1;
    else
    {
        for (int i = index - 1; i < number; i++)
        {
            s[i] = s[i + 1];
        }
        printf("=> 삭제되었습니다\n");
    }

    return number - 1;
}

void saveMbti(mbti_struct *s[], int number)
{
    FILE *fp = fopen("mbti.txt", "w");

    for (int i = 0; i < number; i++)
    {
        fprintf(fp, "%s\n%s\n%d\n%s\n", s[i]->department, s[i]->name, s[i]->s_id, s[i]->mbti);
    }
    fclose(fp);
    printf("=> 저장되었습니다.\n");
}

int loadData(mbti_struct *s[])
{
    int count = 0;
    FILE *fp = fopen("mbti.txt", "r");

    if (fp != NULL)
    {
        while (!feof(fp))
        {
            s[count] = (mbti_struct *)malloc(sizeof(mbti_struct));
            int ret = fscanf(fp, "%[^\n]\n%s\n%s\n%s\n", s[count]->department, s[count]->name, s[count]->s_id, s[count]->mbti);
            if (ret < 2)
                continue;
            count++;
        }
        fclose(fp);
        printf("=> 로딩 성공!\n");
        return count;
    }
    else
    {
        printf("=> 파일 없음\n");
    }

    return count;
}

void searchAssignment1(mbti_struct *s[], int number) // 학부 검색
{
    int scnt = 0;
    char search[100];

    printf("\n검색할 학부는 ? ");
    scanf("%[^\n]", search);
    Clear();
    printf("\n================================================================\n");
    printf("NO.     학부명         이름    학번  mbti\n");
    printf("----------------------------------------------------------------\n");

    for (int i = 0; i < number; i++)
    {
        if (strstr(s[i]->department, search))
        {
            printf("%d.     %-15s  %-4s     %-4s  %s\n", i + 1, s[i]->department, s[i]->name, s[i]->s_id, s[i]->mbti);
            scnt ++;
            }
    }
    if(scnt == 0) printf("=> 검색한 데이터가 없습니다. ");
    printf("\n");
}

void searchAssignment2(mbti_struct *s[], int number) // 이름 
{
    char search_name[100];
    int scnt = 0;
    Clear();
    printf("\n검색할 이름은 ? ");
    scanf("%[^\n]", search_name);
    
    printf("\n================================================================\n");
    printf("NO.     학부명         이름    학번  mbti\n");
    printf("----------------------------------------------------------------\n");

    for (int i = 0; i < number; i++)
    {
        if (strstr(s[i]->name, search_name))
        {
            printf("%d.     %-15s  %-4s     %-4d  %s\n", i + 1, s[i]->department, s[i]->name, s[i]->s_id, s[i]->mbti);
            scnt ++;
            }
    }
    if(scnt == 0) printf("=> 검색한 데이터가 없습니다. ");
    printf("\n");
        }

void searchAssignment4(mbti_struct *s[], int number) // 학번 
{
    int student_id=0;
    int scnt = 0;
    printf("\n검색할 학번은 : ");
    scanf("%d", &student_id);

    printf("\n================================================================\n");
            printf("NO.     학부명         이름    학번  mbti\n");
            printf("----------------------------------------------------------------\n");

    for (int i = 0; i < number; i++)
    {
        if(s[i]->s_id == student_id){
            printf("%d.     %-15s  %-4s     %-4d  %s\n", i + 1, s[i]->department, s[i]->name, s[i]->s_id, s[i]->mbti);
            scnt ++;
            }
    }
    if(scnt == 0) printf("=> 검색한 데이터가 없습니다. ");
    printf("\n");
}

void searchAssignment3(mbti_struct *s[], int number) // mbti 
{
    char search[20];
    int scnt = 0;
    Clear();
    printf("\n검색할 mbti? ");
    scanf("%[^\n]", search);
    
    printf("\n================================================================\n");
            printf("NO.     학부명         이름    학번  mbti\n");
            printf("----------------------------------------------------------------\n");

    for (int i = 0; i < number; i++)
    {
        if (strstr(s[i]->mbti, search))
        {
            printf("%d.     %-15s  %-4s     %-4d  %s\n", i + 1, s[i]->department, s[i]->name, s[i]->s_id, s[i]->mbti);
            scnt ++;
            }
    }
    if(scnt == 0) printf("=> 검색한 데이터가 없습니다. ");
    printf("\n");
        }
