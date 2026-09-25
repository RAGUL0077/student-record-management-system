#ifndef STUDENT_H
#define STUDENT_H

struct student
{
    int roll;
    char name[50];
    float percentage;
    struct student *next;
};

extern struct student *head;

void stud_add(void);
void stud_del(void);
void stud_show(void);
void stud_mod(void);
void stud_save(void);
void stud_load(void);
void stud_sort(void);

#endif
