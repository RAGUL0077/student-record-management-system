#include <stdio.h>
#include <string.h>
#include "student.h"

void stud_sort(void)
{
    char choice;

    if(head == NULL)
    {
        printf("\nNo records available.\n");
        return;
    }

    printf("\nN/n : Sort by Name\n");
    printf("P/p : Sort by Percentage\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &choice);

    if(choice == 'N' || choice == 'n')
    {
        struct student *i;
        struct student *j;

        for(i = head; i != NULL; i = i->next)
        {
            for(j = i->next; j != NULL; j = j->next)
            {
                if(strcmp(i->name, j->name) > 0)
                {
                    int roll;
                    char name[50];
                    float percentage;

                    roll = i->roll;
                    i->roll = j->roll;
                    j->roll = roll;

                    strcpy(name, i->name);
                    strcpy(i->name, j->name);
                    strcpy(j->name, name);

                    percentage = i->percentage;
                    i->percentage = j->percentage;
                    j->percentage = percentage;
                }
            }
        }

        printf("Sorted by name.\n");
    }

    else if(choice == 'P' || choice == 'p')
    {
        struct student *i;
        struct student *j;

        for(i = head; i != NULL; i = i->next)
        {
            for(j = i->next; j != NULL; j = j->next)
            {
                if(i->percentage > j->percentage)
                {
                    int roll;
                    char name[50];
                    float percentage;

                    roll = i->roll;
                    i->roll = j->roll;
                    j->roll = roll;

                    strcpy(name, i->name);
                    strcpy(i->name, j->name);
                    strcpy(j->name, name);

                    percentage = i->percentage;
                    i->percentage = j->percentage;
                    j->percentage = percentage;
                }
            }
        }

        printf("Sorted by percentage.\n");
    }

    else
    {
        printf("Invalid choice.\n");
    }
}
