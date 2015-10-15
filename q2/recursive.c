#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

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
static double diff_in_second(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec-t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / 1000000000.0);
}

int main()
{
    char str[10];
    char c;
    struct timespec start, end;
    double cpu_time1;

    printf("Enter the SORTED string : ");
    gets(str);
    printf("Enter the search character : ");
    scanf("%c",&c);
    clock_gettime(CLOCK_REALTIME, &start);
    fflush(stdin);
    printf("%c\n",smallest_character(str, c));
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time1 = diff_in_second(start, end);
    printf("execution time of recursive : %lf sec\n", cpu_time1);
    return 0;
}