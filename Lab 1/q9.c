#include <stdio.h>
#include <stdlib.h>
void swap(int *arr, int initial_index, int final_index, int direction)
{
    if (final_index == initial_index)
    {
        return;
    }
    int temp = arr[initial_index];
    arr[initial_index] = arr[initial_index + direction];
    arr[initial_index + direction] = temp;
    swap(arr, initial_index + direction, final_index, direction);
}
int main()
{
    int k, n;
    scanf("%d", &k);
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int mid = (1 + k) / 2;
    int index_mid = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == mid)
        {
            index_mid = i;
        }
    }
    int big_mid_swapped = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < mid && i > index_mid)
        {
            swap(a, i, index_mid, -1);
            index_mid++;
        }
        else if (a[i] > mid && i < index_mid)
        {
            swap(a, i, index_mid + big_mid_swapped, 1);
            index_mid--;
            i--;
            big_mid_swapped++;
        }
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}