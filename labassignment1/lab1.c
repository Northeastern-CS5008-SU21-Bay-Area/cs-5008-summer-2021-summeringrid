//Xiaoying Liu
//liu.xiaoying@northeastern.edu

#include<stdio.h>
int main()
{
    int a,b,c, choice;
    
    printf("Enter your choice\n");
    printf(" 1. Addition\n 2. Subtraction\n 3. Multiplication\n 4. Division\n");
    scanf("%d",&choice);
    
    printf("Enter a and b values");
    scanf("%d %d", &a, &b);
    int result;
    double result2;
    switch (choice) {
        case 1:
            result = a + b;
            printf("Addition\nSum=%d\n", result);
            break;
        case 2:
            result = a - b;
            printf("Subtraction\nDifference=%d\n", result);
            break;
        case 3:
            result = a * b;
            printf("Multiplication\nProduct=%d\n", result);
            break;
        case 4:
            result2 = (double)a / (double)b;
            printf("Division\nQuotient=%.2f\n", result2);
            break;
        default:
            printf("Inccorect input. Please Try again.\n");
            break;
    
    return 0;
    }
}
