#include <stdio.h>

unsigned int factorial(int n)
{
    if (n == 0) {
        return 1;
    }

    return n * factorial(n - 1);
}

unsigned int factorial_dp(int n)
{
    unsigned int dp[n + 1];
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        dp[i] = i * dp[i - 1];
    }

    return dp[n];
}

int main(void)
{
    puts("Hello World!");

    for (int i = 0; i < 13; i++) {
        printf("%u\n", factorial(i));
        printf("%u\n", factorial_dp(i));
    }

    return 0;
}