#include <iostream>

using namespace std;

int *mergeTwo(int *arr1, int *arr2, int l1, int l2)
{
    int l = l1 + l2;
    int *merge = (int *)malloc(sizeof(int) * (l + 1));
    merge[0] = l;
    int i = 1;
    int j = 1;
    int k = 1;
    while (i <= l1 && j <= l2)
    {
        if (arr1[i] < arr2[j])
        {
            merge[k] = arr1[i];
            i++;
        }
        else
        {
            merge[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i <= l1)
    {
        merge[k] = arr1[i];
        i++;
        k++;
    }
    while (j <= l2)
    {
        merge[k] = arr2[j];
        j++;
        k++;
    }
    return merge;
}

void merge(int **arr, int length)
{
    if (length == 1)
    {
        return;
    }
    for (int i = 0; i < length / 2; i++)
    {
        arr[i] = mergeTwo(arr[2 * i], arr[(2 * i) + 1], arr[2 * i][0], arr[(2 * i) + 1][0]);
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
    int n = 0;
    cin >> k;
    int **arr = (int **)malloc(sizeof(int *) * k);
    for (int i = 0; i < k; i++)
    {
        int l;
        cin >> l;
        n += l;
        arr[i] = (int *)malloc(sizeof(int) * (l + 1));
        arr[i][0] = l;
        for (int j = 1; j <= l; j++)
        {
            cin >> arr[i][j];
        }
    }
    merge(arr, k);
    for (int i = 1; i <= n; i++)
    {
        cout << arr[0][i] << " ";
    }
    return 0;
}