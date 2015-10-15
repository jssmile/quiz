#include <stdio.h>

char smallest_character(char str[], char c)
{
    if (str[0]!='\0') {
        if (str[0]>c)
            return str[0];
        else {
            return ((smallest_character(str+1,c)<c)?str[0]:smallest_character(str+1,c));
        }
        return str[0];
    }
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