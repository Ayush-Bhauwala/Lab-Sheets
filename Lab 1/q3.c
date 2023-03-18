#include <stdio.h>
#include <stdlib.h>
void subsetSum(int sum, int start_index, int *arr, int length, int *possible, int *indices)
{
    for (int i = start_index; i < length; i++)
    {
        if (sum == arr[i])
        {
            indices[i] = 1;
            *possible = 1;
            return;
        }
    }
    for (int i = start_index; i < length; i++)
    {
        indices[i] = 1;
        subsetSum(sum - arr[i], i + 1, arr, length, possible, indices);
        if (*possible != 1)
            indices[i] = -1;
        else
            return;
    }
}
int main()
{
    int n, s;
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int) * n);
    int *indices = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        indices[i] = -1;
    }
    scanf("%d", &s);
    int possible = 0;
    subsetSum(s, 0, a, n, &possible, indices);
    if (possible || s == 0)
    {
        printf("POSSIBLE\n");
        for (int i = 0; i < n; i++)
        {
            if (indices[i] == 1)
            {
                printf("%d ", i);
            }
        }
    }
    else
    {
        printf("NOT POSSIBLE");
    }
    return 0;
}