#include <stdio.h>
#include <string.h>

struct student
{
    char email[1000];
    char branch[20];
    char id[15];
};

void generateID(struct student *s)
{
    for (int i = 1; i < 5; i++)
    {
        s->id[i - 1] = s->email[i];
    }
    s->id[4] = 'A';
    if (!strcmp(s->branch, "ECE"))
    {
        s->id[5] = 'A';
    }
    else if (!strcmp(s->branch, "EEE"))
    {
        s->id[5] = '3';
    }
    else if (!strcmp(s->branch, "CS"))
    {
        s->id[5] = '7';
    }
    s->id[6] = 'P';
    s->id[7] = 'S';
    for (int i = 5; i < 9; i++)
    {
        s->id[i + 3] = s->email[i];
    }
    s->id[12] = 'H';
}
int main()
{
    struct student s;
    scanf("%s", &s.email);
    scanf("%s", &s.branch);
    generateID(&s);
    printf("%s", s.id);
    return 0;
}