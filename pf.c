#include <stdio.h>
#include <ctype.h>
int main()
{
    int n;
    scanf("%d", &n);
    int h[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &h[i]);
    }

    int max = 0;
    int min = 0;
    for (int i = 0; i < n; i++)
    {
        if (h[max] < h[i])
        {
            max = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (h[min] >= h[i])
        {
            min = i;
        }
    }
    int moves = max + (n - 1 - min);
    if (max > min)
    {
        moves--;
    }
    printf("%d", moves);
}