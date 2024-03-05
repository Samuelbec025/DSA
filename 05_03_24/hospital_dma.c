#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Patient_Info
{
    char name[10];
    char uid[15];
    char disease[30];
    char blood[3];
    int bed;
}per;

void read(per *I, int num)
{
    for(int i = 0; i < num; i++)
    {
        printf("\nEnter Patient%d name: ", i+1);
        scanf("%s", (I + i)->name);
        printf("Enter Unique Id: ");
        scanf("%s", (I + i)->uid);
        printf("Enter Ailment: ");
        scanf("%s", (I + i)->disease);
        printf("Enter Blood Group:");
        scanf("%s", (I + i)->blood);
        printf("Enter Bed No: ");
        scanf("%d", &(I + i)->bed);
    }
}
void search(per *I, int num)
{
    char search[15];
    printf("\n\nSearch: ");
    scanf("%s", search);
    for(int i = 0; i < num; i++)
    {
        if(!strcmp((I + i)->disease, search) || !strcmp((I + i)->blood, search) || !strcmp((I + i)->uid, search) || !strcmp((I + i)->name, search) || atoi(search) == (I + i)->bed)
        {
            printf("\nPatient(%d): %s\t",(i + 1), (I + i)->name);
            printf("%s\t", (I + i)->uid);
            printf("%s\t", (I + i)->disease);
            printf("%s\t", (I + i)->blood);
            printf("%d", (I + i)->bed);
        }
    }
}

void print(per *I,int num)
{
    for(int i=0;i<num;i++)
    {
        printf("\nPatient(%d): %s\t",(i + 1), (I + i)->name);
        printf("%s\t", (I + i)->uid);
        printf("%s\t", (I + i)->disease);
        printf("%s\t", (I + i)->blood);
        printf("%d", (I + i)->bed);
    }
}

int main()
{
    int num;
    printf("Enter the no.of Patients:");
    scanf("%d",&num);
    per  *I;
    I = (per*)calloc(num,sizeof(per));
    read(I,num);
    print(I,num);
    search(I,num);
    free(I);
    return 0;
}
