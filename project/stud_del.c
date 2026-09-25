#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void stud_del(void)
{
    char choice;

    if(head == NULL)
    {
        printf("\nNo records available.\n");
        return;
    }

    printf("\nR/r : Delete using Roll Number\n");
    printf("N/n : Delete using Name\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &choice);

    /*
       Delete using roll number
    */
    if(choice == 'R' || choice == 'r')
    {
        int roll;
        struct student *temp;
        struct student *prev = NULL;

        printf("Enter Roll Number: ");
        scanf("%d", &roll);

        temp = head;

        while(temp != NULL)
        {
            if(temp->roll == roll)
                break;

            prev = temp;
            temp = temp->next;
        }

        if(temp == NULL)
        {
            printf("Record not found.\n");
            return;
        }

        if(prev == NULL)
        {
            head = temp->next;
        }
        else
        {
            prev->next = temp->next;
        }

        free(temp);

        printf("Record deleted successfully.\n");
    }

    /*
       Delete using name
    */
    else if(choice == 'N' || choice == 'n')
    {
        char name[50];
        struct student *temp;
        int found = 0;
        int roll;

        printf("Enter Name: ");
        scanf(" %[^\n]", name);

        temp = head;

        printf("\nMatching Records:\n");
        printf("--------------------------------------\n");

        while(temp != NULL)
        {
            if(strcmp(temp->name, name) == 0)
            {
                printf("Roll: %d  Name: %s  Percentage: %.2f\n",
                       temp->roll,
                       temp->name,
                       temp->percentage);

                found = 1;
            }

            temp = temp->next;
        }

        if(found == 0)
        {
            printf("No matching records found.\n");
            return;
        }

        printf("Enter Roll Number to Delete: ");
        scanf("%d", &roll);

        temp = head;

        struct student *prev = NULL;

        while(temp != NULL)
        {
            if(temp->roll == roll)
                break;

            prev = temp;
            temp = temp->next;
        }

        if(temp == NULL)
        {
            printf("Record not found.\n");
            return;
        }

        if(prev == NULL)
        {
            head = temp->next;
        }
        else
        {
            prev->next = temp->next;
        }

        free(temp);

        printf("Record deleted successfully.\n");
    }

    else
    {
        printf("Invalid choice.\n");
    }
}
