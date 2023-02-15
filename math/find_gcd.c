/**
 * @file find_gcd.c
 *
 * @brief Find Greatest Common Divisor of two numbers
 *
 */

#include <stdio.h>

// Euclidean algorithm
int find_gcd_1(int a, int b)
{
    while (a != 0 && b != 0) {
        if (a >= b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    if (a) {
        return a;
    } else {
        return b;
    }
}

// without if-else-state
int find_gcd_2(int a, int b)
{
    while (a != 0) {
        int tmp = a;
        a = b;
        b = tmp;
        a = a % b;
    }

    return b;
}

// recursion
int find_gcd_3(int a, int b)
{
    if (a <= 0) {
        return b;
    }

    return find_gcd_3(b % a, a);
}

#include <sys/time.h>

int main(void)
{
    int a = 98;
    int b = 154;

    int gcd_1 = find_gcd_1(a, b);
    int gcd_2 = find_gcd_2(a, b);
    int gcd_3 = find_gcd_3(a, b);


    printf("GCD (%d, %d) = %d\n", a, b, gcd_1);
    printf("GCD (%d, %d) = %d\n", a, b, gcd_2);
    printf("GCD (%d, %d) = %d\n", a, b, gcd_3);


    printf("GCD (%d, %d) = %d\n", 314, 193, find_gcd_3(14, 193));
    printf("GCD (%d, %d) = %d\n", 224, 290, find_gcd_3(224, 90));
    printf("GCD (%d, %d) = %d\n", 422, 238, find_gcd_3(22, 238));
    printf("GCD (%d, %d) = %d\n", 596, 108, find_gcd_3(96, 108));
    printf("GCD (%d, %d) = %d\n", 188, 224, find_gcd_3(188, 224));
    printf("GCD (%d, %d) = %d\n", 154, 252, find_gcd_3(153, 252));
    printf("GCD (%d, %d) = %d\n", 179, 694, find_gcd_3(179, 94));
    printf("GCD (%d, %d) = %d\n", 168, 244, find_gcd_3(168, 244));
    printf("GCD (%d, %d) = %d\n", 851, 130, find_gcd_3(51, 130));
    printf("GCD (%d, %d) = %d\n", 116, 148, find_gcd_3(116, 148));
    printf("GCD (%d, %d) = %d\n", 168, 246, find_gcd_3(168, 246));
    printf("GCD (%d, %d) = %d\n", 232, 178, find_gcd_3(32, 178));

    return 0;
}
