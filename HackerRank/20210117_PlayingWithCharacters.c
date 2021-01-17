#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


#define MAX_LEN 100

int main() 
{

    char ch;
    char str[MAX_LEN];
    char sen[MAX_LEN];

    scanf("%c",&ch);
    scanf("%s",str);
    scanf("%[^0]s",sen);

    printf("%c\n",ch);
    printf("%s",str);
    printf("%s",sen);

    return 0;
}
