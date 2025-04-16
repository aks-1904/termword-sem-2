#include <stdio.h>

void computeGCDandLCM(int a, int b, int *gcd, int *lcm)
{
    int x = a, y = b;

    while (y != 0)
    {
        int temp = y;
        y = x % y;
        x = temp;
    }
    *gcd = x;

    *lcm = (a * b) / (*gcd);
}

void main()
{
    int num1, num2;
    int gcd, lcm;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    computeGCDandLCM(num1, num2, &gcd, &lcm);

    printf("GCD of %d and %d = %d\n", num1, num2, gcd);
    printf("LCM of %d and %d = %d\n", num1, num2, lcm);
}
