#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int min_positif = 5526;
    int min_negatif = -273;
    int result = 0;
    int temp;
    int n; // the number of temperatures to analyse
    n = 1;
    if (n != 0)
    {
        for (int i = 0; i < n; i++)
        {
            // a temperature expressed as an integer ranging from -273 to 5526
            int t;
            t = 85996;
            if (t > 0 && t <= 5526 &&n == 1)
            {
                temp = 1;
                min_positif = t; 
            }
            else if (t > 0 && t <= min_positif)
            {
                min_positif = t;
            }
            else if (t < 0 && t >= min_negatif)
            {
                min_negatif = t;
            }
            else
            {
                result = 0;
            }
        }
        if (temp != 1)
        {
            if (abs(min_positif) > abs(min_negatif))
            {
                result = min_negatif;
            }
            else if (abs(min_positif) < abs(min_negatif))
            {
                result = min_positif;
            }
            else if (abs(min_positif) == abs(min_negatif))
            {
                result = min_positif;
            }
        }
        else
        {
            result = min_positif;
        }

        printf("%d\n", result);
    }
    else
    {
        printf("%d\n", result);
    }
    return 0;
}