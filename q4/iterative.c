#include <stdlib.h>
#include <stdio.h>

int maxSubArray(int arr[], int len)
{
    int sum = 0;
    int largestsum = arr[0];
    for(int j = 0; j < len; j++) {
        if(sum > 0) sum += arr[j];
        else sum = arr[j];
        if(largestsum < sum) largestsum = sum;
    }
    return largestsum;
}

int main()
{
    int array[9] =  {-2,1,-3,4,-1,2,1,-5,4};

    int len = sizeof(array)/sizeof(array[0]);
    int result = maxSubArray(array, len);
    printf("%d\n",result);
    return 0;
}