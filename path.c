#include <stdio.h>
#include <stdlib.h>
int main()
{
        int i = 0;
        char* s = getenv("PATH");

        printf("test\n");
        while (s[i] != '\0')
        {
                printf("%c", s[i]);
                if (s[i] == ':')
                {
                        printf("\n");
                }
                i++;
        }
        printf("\n");
        printf("end test\n");
}
