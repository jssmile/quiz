#include <stdio.h>

char smallest_character(char str[], char c)
{
    for (int i=0; i<sizeof(str); i++)
        if(str[i]>c)return str[i];
    return str[0];
}

int main()
{
    char str[10];
    char c;
    printf("Enter the SORTED string : ");
    gets(str);
    printf("Enter the search character : ");
    scanf("%c",&c);
    fflush(stdin);
    printf("%c\n",smallest_character(str, c));
    return 0;
}
