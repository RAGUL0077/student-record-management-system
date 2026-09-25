#include <stdio.h>
#include "student.h"

void stud_show(void)
{
    struct student *temp;

    if(head == NULL)
    {
        printf("\nNo records available.\n");
        return;
    }

    printf("\n--------------------------------------\n");
    printf("Roll No\tName\t\tPercentage\n");
    printf("--------------------------------------\n");

    temp = head;

    while(temp != NULL)
    {
        printf("%d\t%-15s %.2f\n",
               temp->roll,
               temp->name,
               temp->percentage);

        temp = temp->next;
    }

    printf("--------------------------------------\n");
}
