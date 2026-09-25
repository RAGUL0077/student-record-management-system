#include <stdio.h>
#include "student.h"
#include "stud_add.c"
#include "stud_del.c"
#include "stud_mod.c"
#include "stud_save.c"
#include "stud_show.c"
#include "stud_sort.c"
struct student *head = NULL;

int main()
{
    char choice;

    /* Load existing records */
    stud_load();

    while(1)
    {
        printf("\n**** STUDENT RECORD MENU ****\n");
        printf("A/a : Add New Record\n");
        printf("D/d : Delete a Record\n");
        printf("S/s : Show the List\n");
        printf("M/m : Modify a Record\n");
        printf("V/v : Save\n");
        printf("T/t : Sort the List\n");
        printf("E/e : Exit\n");

        printf("Enter Your Choice: ");
        scanf(" %c", &choice);

        switch(choice)
        {
            case 'A':
            case 'a':
                stud_add();
                break;

            case 'D':
            case 'd':
                stud_del();
                break;

            case 'S':
            case 's':
                stud_show();
                break;

            case 'M':
            case 'm':
                stud_mod();
                break;

            case 'V':
            case 'v':
                stud_save();
                break;

            case 'T':
            case 't':
                stud_sort();
                break;

            case 'E':
            case 'e':
            {
                char ch;

                printf("\nS/s : Save and Exit\n");
                printf("E/e : Exit Without Saving\n");
                printf("Enter Your Choice: ");
                scanf(" %c", &ch);

                if(ch == 'S' || ch == 's')
                {
                    stud_save();
                    printf("Saved. Exiting...\n");
                    return 0;
                }
                else if(ch == 'E' || ch == 'e')
                {
                    printf("Exiting without saving...\n");
                    return 0;
                }
                else
                {
                    printf("Invalid choice\n");
                }

                break;
            }

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
