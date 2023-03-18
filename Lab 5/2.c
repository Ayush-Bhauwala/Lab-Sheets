#include <stdio.h>
#define int long long

int alternateDeath(int start, int end, int step, int initial, int totalKilled, int direction)
{
    int killed = 1 + (direction * (end - start) / (2 * step));
    int lastKilled = start + ((direction) * (killed - 1) * (2 * step));
    int newStart = lastKilled + (direction * step) == end ? end : lastKilled - (direction * step);
    if (initial - totalKilled == 1)
        return newStart;
    return alternateDeath(newStart, start + (direction * step), 2 * step, initial, totalKilled + killed, -direction);
}

int main()
{
    int n;
    scanf("%lld", &n);
    int alive = alternateDeath(1, n, 1, n, 0, 1);
    printf("%lld", alive);
    return 0;
}