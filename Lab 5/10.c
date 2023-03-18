#include <stdio.h>
#include <stdlib.h>
#define int long long
#include <time.h>

int main()
{
    int n;
    scanf("%lld", &n);
    int count = 0;
    int ans;
    srand(time(NULL));
    while (count < n)
    {
        int x;
        scanf("%lld", &x);
        count++;
        if (count == 1)
            ans = x;
        else
        {
            int i = rand() % count;
            if (i == count - 1)
                ans = x;
        }
        printf("** %lld **\n", ans);
    }
    return 0;
}