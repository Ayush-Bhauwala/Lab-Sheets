#include <stdio.h>
#include <stdlib.h>
#define ll long long

ll main()
{
    ll n;
    scanf("%lld ", &n);
    ll *a = (ll *)malloc(sizeof(ll) * n);
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    return 0;
}