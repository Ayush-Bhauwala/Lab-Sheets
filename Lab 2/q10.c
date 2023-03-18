#include <stdio.h>
#include <stdlib.h>

struct country
{
    char name[20];
    int gold;
    int silver;
    int bronze;
};

int main()
{
    int n;
    scanf("%d", &n);
    struct country *countries = (struct country *)malloc(sizeof(struct country) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d %d", &countries[i].name, &countries[i].gold, &countries[i].silver, &countries[i].bronze);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if ((countries[j].gold < countries[j + 1].gold) || (countries[j].gold == countries[j + 1].gold && countries[j].silver < countries[j + 1].silver) || (countries[j].gold == countries[j + 1].gold && countries[j].silver == countries[j + 1].silver && countries[j].bronze < countries[j + 1].bronze))
            {
                struct country temp = countries[j];
                countries[j] = countries[j + 1];
                countries[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", countries[i].name);
    }
    return 0;
}