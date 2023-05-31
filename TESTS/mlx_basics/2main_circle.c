#include <stdio.h>

#include <math.h>

int main ()
{
    int i = 0;
    int j = 0;
    int r = 10;
    int x = 10;
    int y = 10;
    int d;
    int a;
    
    while (i < 24)
    {
        while ( j < 25)
        {
            a = ((i - x) * (i - x)) + ((j - y) * (j - y));
            d = sqrt(a);
            if (r == d)
                printf("*");
            else
                printf(" ");
            ++j;
        }
        printf("\n");
        j = 0;
        ++i;
    }
    return 0;
}

// for(i=0;i<24;i++)
//     {
//        for(j=0;j<25;j++)
//        {
//             a=((i-x)*(i-x))+((j-y)*(j-y));
//             d=sqrt(a);
//             if(r==d)
//             {
//                 printf("*");
//             }
//             else
//                 printf(" ");
//         }
//         printf("\n");
//     }