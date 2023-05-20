#include "mbti.h"

int main()
{
    mbti_struct *s[20];
    int number = 0;
    int menu, choice = 0;

    number = loadData(s);

    while (1){
        menu = selectMenu();
        Clear();
        if (menu == 0)
            break;
        if (menu == 1)
            number = createMbti(s, number);
        else if (menu == 2)
            readMbti(s, number);
        else if (menu == 3)
            updateMbti(s, number);
        else if (menu == 4)
            number = deleteMbti(s, number);
        else if (menu == 5)
            saveMbti(s, number);
        else if (menu == 6){
            while (1){
                printf("기능(1:학부, 2:이름, 3:mbti, 4:학번) : ");
                scanf("%d", &choice);
                if (choice == 1){
                    Clear();
                    searchMbti1(s, number);
                    break;
                }
                else if (choice == 2) {
                    searchMbti2(s, number);
                    break;
                }
                else if (choice == 3){
                    searchMbti3(s, number);
                    break;
                }
                else if (choice == 4){
                    searchMbti4(s, number);
                    break;
                }
                else{
                    printf("기능(1:학부, 2:이름, 3:mbti, 4:학번) : ");
                    scanf("%d", &choice);
                }
            }
        }
	else if (menu == 7){
		while(1){
			printf("통계 결과 (1. 순위, 2. 학부 통계, 3. 성별 통계) : ");
			scanf("%d", &choice);
			if(choice == 1){
				Clear();
				findBest(s, number);
				break;
			}
			else if(choice == 2){
				Clear();
				graphDepartment(s, number);
				break;
			}
			else if(choice == 3){
				Clear();
				graphSex(s, number);
				break;
			}
			else{
				printf("통계 결과 (1. 순위, 2. 학부 통계, 3. 성별 통계) : ");
				scanf("%d", &choice);
			}
		}
	}
	else if (menu == 8){
		printMbtiInfo();
	}
    }
    printf("=> 종료\n");

    for(int i=0; i<number; i++){
	    free(s[i]);
	}
    return 0;
}
