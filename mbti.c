#include "mbti.h"

int selectMenu() {
    int menu;
    printf("\n*** mbti 결과 분석 서비스 ***\n");
    printf("1. 추가\n");
    printf("2. 조회\n");
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

int createMbti(mbti_struct *s[], int number){
	s[number] = malloc(sizeof(mbti_struct));
        printf("이름은? ");
        scanf("%[^\n]", s[number]->name);
	getchar();
        printf("성별은? ");
        scanf("%[^\n]", s[number]->sex);
	getchar();
        printf("학부는? ");
        scanf("%[^\n]", s[number]->department);
	getchar();
        printf("학번은? ");
        scanf("%s", s[number]->s_id);
	getchar();
        printf("MBTI는? ");
        scanf("%[^\n]", s[number]->mbti);
	getchar();
	number++;
        printf("=> 추가됨!\n");
        return number;
}

void readMbti(mbti_struct *s[], int number) {
    printf("\n================================================================\n");
    printf("NO.   학부명          이름         성별   학번    mbti\n");
    printf("----------------------------------------------------------------\n");

    for (int i = 0; i < number; i++) {
        printf("%-4d %-15s %-17s %-8s %-9s %s\n", i + 1, s[i]->department, s[i]->name, s[i]->sex, s[i]->s_id, s[i]->mbti);
    }

    printf("\n");
}

void updateMbti(mbti_struct *s[], int number){
	char name[100];
	int found = 0;

	printf("수정할 이름은? ");
	scanf("%[^\n]", name);
	getchar();

	for(int i=0; i<number; i++){
		if(strcmp(s[i]->name, name) == 0){
			found = 1;
        printf("이름은? ");
        scanf("%[^\n]", s[i]->name);
        getchar();
        printf("성별은? ");
        scanf("%[^\n]", s[i]->sex);
        getchar();
        printf("학부는? ");
        scanf("%[^\n]", s[i]->department);
        getchar();
        printf("학번은? ");
        scanf("%s", s[i]->s_id);
	getchar();
        printf("MBTI는? ");
        scanf("%[^\n]", s[i]->mbti);
        getchar();
        printf("=> 수정됨!\n");
	break;
	}
	}
	if(!found){
		printf("일치하는 정보가 없습니다.\n");
	}
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
        fprintf(fp, "%s\n%s\n%s\n%s\n", s[i]->department, s[i]->name, s[i]->s_id, s[i]->mbti);
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

void searchMbti1(mbti_struct *s[], int number) // 학부 검색
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

void searchMbti2(mbti_struct *s[], int number) // 이름 
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
            printf("%d.     %-15s  %-4s     %-4s  %s\n", i + 1, s[i]->department, s[i]->name, s[i]->s_id, s[i]->mbti);
            scnt ++;
            }
    }
    if(scnt == 0) printf("=> 검색한 데이터가 없습니다. ");
    printf("\n");
        }

void searchMbti4(mbti_struct *s[], int number) // 학번 
{
    char student_id[50];
    int scnt = 0;
    printf("\n검색할 학번은 : ");
    scanf("%s", student_id);

    printf("\n================================================================\n");
            printf("NO.     학부명         이름    학번  mbti\n");
            printf("----------------------------------------------------------------\n");

    for (int i = 0; i < number; i++)
    {
        if(strstr(s[i]->s_id , student_id)){
            printf("%d.     %-15s  %-4s     %-4s  %s\n", i + 1, s[i]->department, s[i]->name, s[i]->s_id, s[i]->mbti);
            scnt ++;
            }
    }
    if(scnt == 0) printf("=> 검색한 데이터가 없습니다. ");
    printf("\n");
}

void searchMbti3(mbti_struct *s[], int number) // mbti 
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
            printf("%d.     %-15s  %-4s     %-4s  %s\n", i + 1, s[i]->department, s[i]->name, s[i]->s_id, s[i]->mbti);
            scnt ++;
            }
    }
    if(scnt == 0) printf("=> 검색한 데이터가 없습니다. ");
    printf("\n");
        }

void printMbtiInfo(){
	char file[20]; //파일이름
	FILE* data;

	printf("MBTI를 입력하시오. ");
	scanf("%s", file);
	strcat(file,  ".txt");
	
	data = fopen(file, "r");
	if(data == NULL){
		printf("파일을 열 수 없습니다.\n");
		return;
	}
	
	char line[1000];
	printf("\n");
	while(fgets(line, sizeof(line), data) != NULL){
		printf("%s", line);
	}
	fclose(data);
}

void findBest(mbti_struct *s[], int number){
    int count[16] = {0};
    char typename[16][10] = {"ESTP", "ESTJ", "ESFP", "ESFJ", "ENTP", "ENTJ", "ENFP", "ENFJ",
     "ISTP", "ISTJ", "ISFP", "ISFJ", "INTP", "INTJ", "INFP", "INFJ"};

    for(int i=0; i<number; i++){
        for(int j=0; j<16; j++){
            if(strcmp(s[i]->mbti, typename[j]) == 0){
                count[j]++;
		break;
            }
        }
    }

    for(int i=0; i<16; i++){
        for(int j=0; j<16-1-i; j++){
            if(count[j]<count[j+1]){
		int temp = count[j];
		count[j] = count[j+1];
		count[j+1] = temp;

		char tempType[5];
                strcpy(tempType, typename[j]);
                strcpy(typename[j], typename[j+1]);
                strcpy(typename[j+1], tempType);
            }
        }
    }

    printf("MBTI 분포도 순위\n");
    printf("---------------------\n");
    for(int i=0; i<16; i++){
       printf("%d. %s\n", i+1, typename[i]);
    }
    
}

void graphSex(mbti_struct *s[], int number){
    int num[16] = {0};
    char sex[100];
    char typename[16][5] = {"ESTP", "ESTJ", "ESFP", "ESFJ", "ENTP", "ENTJ", "ENFP", "ENFJ",
     "ISTP", "ISTJ", "ISFP", "ISFJ", "INTP", "INTJ", "INFP", "INFJ"};

    printf("검색할 성별은? ");
    scanf(" %[^\n]", sex);
    Clear();

    printf("성별: %s\n", sex);
    for(int i=0; i<number; i++){
        if(strstr(s[i]->sex, sex)){
            for(int j=0; j<16; j++){
                if(strstr(s[i]->mbti, typename[j])){
                    num[j]++;
                }
            }
        }
    }

    for(int i=0; i<16; i++){
        printf("%s | ", typename[i]);
        for(int j=0; j<num[i]; j++) printf("*");
        printf("\n");
    }

}

void graphDepartment(mbti_struct *s[], int number){
    int num[16]= {0};
    char department[100];
    char typename[16][5] = {"ESTP", "ESTJ", "ESFP", "ESFJ", "ENTP", "ENTJ", "ENFP", "ENFJ",
     "ISTP", "ISTJ", "ISFP", "ISFJ", "INTP", "INTJ", "INFP", "INFJ"};

    printf("검색할 학부는? ");
    scanf(" %[^\n]", department);
    Clear();

    printf("학부명: %s\n", department);
    int found = 0;
    for(int i=0; i<number; i++){
        if(strstr(s[i]->department, department)){
           	found = 1;
	       	for(int j=0; j<16; j++){
                if(strstr(s[i]->mbti, typename[j])){
                    num[j]++;
                }
            }
        }
    }

    if(!found){
	    printf("검색된 학부가 없습니다.\n");
	    return;

    }
    for(int i=0; i<16; i++){
        printf("%s | ", typename[i]);
        for(int j=0; j<num[i]; j++) printf("*");
        printf("\n");
    }

}
	
