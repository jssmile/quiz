#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int maxSubArray(int A[], int len)
{
    int sum = 0;
    int largestsum = A[0];
    for(int j = 0; j < len; j++) {
        if(sum > 0) sum += A[j];
        else sum = A[j];
        if(largestsum < sum) largestsum = sum;
    }
    return largestsum;
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
    int array[9] =  {-2,1,-3,4,-1,2,1,-5,4};
    struct timespec start, end;
    double cpu_time1;

    int len = sizeof(array)/sizeof(array[0]);
    clock_gettime(CLOCK_REALTIME, &start);
    int result = maxSubArray(array, len);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time1 = diff_in_second(start, end);
    printf("%d\n",result);
    printf("execution time of iterative : %lf sec\n", cpu_time1);
    return 0;
}