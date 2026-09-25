#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void stud_save(void)
{
    FILE *fp;
    struct student *temp;

    fp = fopen("student.dat", "wb");

    if(fp == NULL)
    {
        printf("Unable to open file.\n");
        return;
    }

    temp = head;

    while(temp != NULL)
    {
        fwrite(&temp->roll, sizeof(int), 1, fp);
        fwrite(temp->name, sizeof(temp->name), 1, fp);
        fwrite(&temp->percentage, sizeof(float), 1, fp);

        temp = temp->next;
    }

    fclose(fp);

    printf("Records saved successfully.\n");
}


void stud_load(void)
{
    FILE *fp;
    struct student *new;
    struct student *temp;

    int roll;
    char name[50];
    float percentage;

    fp = fopen("student.dat", "rb");

    if(fp == NULL)
    {
        return;
    }

    while(1)
    {
        if(fread(&roll, sizeof(int), 1, fp) != 1)
            break;

        if(fread(name, sizeof(name), 1, fp) != 1)
            break;

        if(fread(&percentage, sizeof(float), 1, fp) != 1)
            break;

        new = malloc(sizeof(struct student));

        if(new == NULL)
        {
            printf("Memory allocation failed.\n");
            fclose(fp);
            return;
        }

        new->roll = roll;

        for(int i = 0; i < 50; i++)
            new->name[i] = name[i];

        new->percentage = percentage;
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
    }

    fclose(fp);
}
