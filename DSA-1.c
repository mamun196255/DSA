#include <stdio.h>

int main()
{
    int a[100] = {2, 5, 2, 4, 2, 7, 9, 8, 4};
    int n = 9;
    int b[100];
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        int found = 0;
        for (int k = 0; k < j; k++)
        {
            if (b[k] == a[i])
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            b[j] = a[i];
            j++;
        }
    }

    for (int i = 0; i < j; i++)
    {
        printf("%d ", b[i]);
    }
return 0;
}