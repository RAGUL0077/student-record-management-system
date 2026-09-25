#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void stud_add(void)
{
    struct student *new;
    struct student *temp;
    int roll = 1;

    new = malloc(sizeof(struct student));

    if(new == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    /*
       Find the smallest available roll number
    */
    while(1)
    {
        temp = head;

        while(temp != NULL)
        {
            if(temp->roll == roll)
                break;

            temp = temp->next;
        }

        if(temp == NULL)
            break;

        roll++;
    }

    new->roll = roll;

    printf("Enter Student Name: ");
    scanf(" %[^\n]", new->name);

    printf("Enter Percentage: ");
    scanf("%f", &new->percentage);

    new->next = NULL;

    if(head == NULL)
    {
        head = new;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = new;
    }

    printf("\nRecord added successfully!\n");
    printf("Roll Number : %d\n", new->roll);
}
