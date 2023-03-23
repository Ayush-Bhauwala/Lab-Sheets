#include <iostream>
using namespace std;

#define ll long long

int *mergeTwo(int *arr1, int *arr2, int length1, int length2)
{
    int length = length1 + length2;
    int *merged = (int *)malloc(sizeof(int) * (length + 1));
    merged[0] = length;
    int i = 1;
    int j = 1;
    int k = 1;
    while (i <= length1 && j <= length2)
    {
        if (arr1[i] < arr2[j])
        {
            merged[k] = arr1[i];
            i++;
        }
        else
        {
            merged[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i <= length1)
    {
        merged[k] = arr1[i];
        i++;
        k++;
    }
    while (j <= length2)
    {
        merged[k] = arr2[j];
        j++;
        k++;
    }
    return merged;
}

void merge(int **arr, int length)
{
    if (length == 1)
    {
        return;
    }
    for (int i = 0; i < length / 2; i++)
    {
        int *merged = mergeTwo(arr[(2 * i)], arr[(2 * i) + 1], arr[(2 * i)][0], arr[(2 * i) + 1][0]);
        arr[i] = merged;
    }
    if (length % 2)
    {
        arr[length / 2] = arr[length - 1];
    }
    merge(arr, length / 2 + (length % 2));
}

int main()
{
    int k;
    cin >> k;
    int **arr = (int **)malloc(sizeof(int *) * (k));
    int n = 0;
    for (int i = 0; i < k; i++)
    {
        int l;
        cin >> l;
        n += l;
        arr[i] = (int *)malloc(sizeof(int) * (l + 1));
        arr[i][0] = l;
        for (int j = 1; j < l + 1; j++)
        {
            cin >> arr[i][j];
        }
    }
    merge(arr, k);
    for (int i = 1; i < n + 1; i++)
    {
        cout << arr[0][i];
        cout << " ";
    }
    return 0;
}