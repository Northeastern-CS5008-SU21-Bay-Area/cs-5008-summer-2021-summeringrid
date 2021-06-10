//Xiaoying Liu
//liu.xiaoying@northeastern.edu
#include<stdio.h>

int fact(int n)
{
    if(n==0){
        return 1;
    }
    else {
        return n*fact(n-1);
    }
}

int main()
{
    printf("Input number n: ");
    int n;
    scanf("%d", &n);
    printf("Factorial of number %d is %d\n", n, fact(n));
    
    return 0;
}
