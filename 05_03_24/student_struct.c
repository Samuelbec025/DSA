#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student_Info
{
    char name[10];
    char usn[15];
    int roll;
    int sem;
    float cgpa;
}per;

void read(per I[],int num)
{
    for(int i = 0; i < num; i++)
    {
        printf("Enter student%d name: ",i+1);
        scanf("%s", I[i].name);
        printf("Enter USN: ");
        scanf("%s", I[i].usn);
        printf("Enter Roll No: ");
        scanf("%d", &I[i].roll);
        printf("Enter Sem:");
        scanf("%d", &I[i].sem);
        printf("Enter CGPA: ");
        scanf("%f", &I[i].cgpa);
    }
}
void search(per I[], int num)
{
    char search[15];
    printf("\n\nEnter the USN: ");
    scanf("%s", search);
    for(int i = 0; i < num; i++)
    {
        int result = strcmp(I[i].usn, search);
        if(result == 1)
        {
            printf("USN Found!!!");
            printf("\nName: %s", I[i].name);
            printf("\nRoll No: %d", I[i].roll);
            printf("\nSem: %d", I[i].sem);
            printf("\nCGPA: %0.2f", I[i].cgpa);
        }
        else
        {
            printf("USN not Found!!!");
        }
    }
}

void print(per I[],int num)
{
    for(int i=0;i<num;i++)
    {
        printf("\nStudent-%d details: ",i+1);
        printf("%s\t", I[i].name);
        printf("%s\t", I[i].usn);
        printf("%d\t", I[i].roll);
        printf("%d\t", I[i].sem);
        if(I[i].cgpa >= 1 && I[i].cgpa <= 10)
            printf("%0.2f", I[i].cgpa);
        else
            printf("Invalid CGPA!!!");
    }
}

int main()
{
    int num;
    printf("Enter the no.of students:");
    scanf("%d",&num);
    per  *I;
    I = (per*)calloc(num,sizeof(per));
    read(I,num);
    print(I,num);
    search(I,num);
    free(I);
    return 0;
}
