#include <stdio.h>
#include <stdlib.h>
#define ll long long

ll main()
{
    ll n;
    scanf("%lld", &n);
    ll *arr = (ll *)malloc(sizeof(ll) * n);
    ll max = 0;
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
        if (arr[i] > max)
            max = arr[i];
    }
    ll *freq = (ll *)malloc(sizeof(ll) * (max + 1));
    for (ll i = 0; i < max + 1; i++)
    {
        freq[i] = 0;
    }
    for (ll i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    ll first = 0;
    for (ll i = 0; i < n;)
    {
    }
    prllf("\n");
    return 0;
}