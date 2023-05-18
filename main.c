#include "main.h"

int main()
{
    struct mbti_struct *s[20];
    int number = 0;
    int menu, choice = 0;

    number = loadData(s);

    while (1)
    {
        menu = selectMbti();
        Clear();
        if (menu == 0)
            break;
        if (menu == 1)
            number = createMbti(s, number);
        else if (menu == 2)
            readMbti(s, number);
        else if (menu == 3)
            number = updateMbti(s, number);
        else if (menu == 4)
            number = deleteMbti(s, number);
        else if (menu == 5)
            saveMbti(s, number);
        else if (menu == 6)
        {
            while (1)
            {
                printf("기능(1:학부, 2:이름, 3:mbti, 4:학번) : ");
                scanf("%d", &choice);
                if (choice == 1)
                {
                    Clear();
                    searchAssignment1(s, number);
                    break;
                }
                else if (choice == 2)
                {
                    searchAssignment2(s, number);
                    break;
                }
                else if (choice == 3)
                {
                    searchAssignment3(s, number);
                    break;
                }
                else if (choice == 4)
                {
                    searchAssignment4(s, number);
                    break;
                }
                else
                {
                    printf("기능(1:학부, 2:이름, 3:mbti, 4:학번) : ");
                    scanf("%d", &choice);
                }
            }
        }
    }
    printf("=> 종료\n");

    free(*s);
    return 0;
}
