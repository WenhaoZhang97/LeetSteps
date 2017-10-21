/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Note:
The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.
*/

#include<limits.h>

int reverse(int x) {
    int is_nega=0;
    double result=0;
    int min=INT_MIN,max=INT_MAX;
    if(x<0){
        is_nega=1;
        x=-1*x;
    }
    while(x){
        result*=10;
        if(result>(double)INT_MAX)
            return 0;
        if(result<(double)INT_MIN)
            return 0;
        int temp=x%10;
        x/=10;
        result+=temp;
    }
    if(is_nega)
        result*=-1;
    return result;
}