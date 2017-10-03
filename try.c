#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
int t,i,c=1,j=1;
    char s[10];
    scanf("%d",&t);
    for(i=0;i<t;i++)
        {scanf("%s",s);
        for(int j=0;((2*j))<strlen(s);j++)
            {
                printf("%c",s[(2*j)]);
            }
             printf(" ");
         for(int j=0;((2*j)+1)<strlen(s);j++)
            {
                printf("%c",s[(2*j)+1]);
            }
            
printf("\n");
        }
    return 0;
}
