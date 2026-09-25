#include <stdio.h>
#include <string.h>
#include "student.h"

void stud_mod(void)
{
    char choice;
    struct student *temp;
    struct student *selected = NULL;

    if(head == NULL)
    {
        printf("\nNo records available.\n");
        return;
    }

    printf("\nR/r : Roll Number\n");
    printf("N/n : Name\n");
    printf("P/p : Percentage\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &choice);

    /*
       Search using roll number
    */
    if(choice == 'R' || choice == 'r')
    {
        int roll;

        printf("Enter Roll Number: ");
        scanf("%d", &roll);

        temp = head;

        while(temp != NULL)
        {
            if(temp->roll == roll)
            {
                selected = temp;
                break;
            }

            temp = temp->next;
        }
    }

    /*
       Search using name
    */
    else if(choice == 'N' || choice == 'n')
    {
        char name[50];
        int found = 0;

        printf("Enter Name: ");
        scanf(" %[^\n]", name);

        temp = head;

        printf("\nMatching Records:\n");

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

        int roll;

        printf("Enter Roll Number: ");
        scanf("%d", &roll);

        temp = head;

        while(temp != NULL)
        {
            if(temp->roll == roll)
            {
                selected = temp;
                break;
            }

            temp = temp->next;
        }
    }

    /*
       Search using percentage
    */
    else if(choice == 'P' || choice == 'p')
    {
        float percentage;
        int found = 0;

        printf("Enter Percentage: ");
        scanf("%f", &percentage);

        temp = head;

        printf("\nMatching Records:\n");

        while(temp != NULL)
        {
            if(temp->percentage == percentage)
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

        int roll;

        printf("Enter Roll Number: ");
        scanf("%d", &roll);

        temp = head;

        while(temp != NULL)
        {
            if(temp->roll == roll)
            {
                selected = temp;
                break;
            }

            temp = temp->next;
        }
    }

    else
    {
        printf("Invalid choice.\n");
        return;
    }

    if(selected == NULL)
    {
        printf("Record not found.\n");
        return;
    }

    /*
       Modify field
    */

    printf("\nN/n : Name\n");
    printf("P/p : Percentage\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &choice);

    if(choice == 'N' || choice == 'n')
    {
        printf("Enter New Name: ");
        scanf(" %[^\n]", selected->name);

        printf("Name modified successfully.\n");
    }
    else if(choice == 'P' || choice == 'p')
    {
        printf("Enter New Percentage: ");
        scanf("%f", &selected->percentage);

        printf("Percentage modified successfully.\n");
    }
    else
    {
        printf("Invalid choice.\n");
    }
}
