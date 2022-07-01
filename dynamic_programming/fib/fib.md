
### Recursion

```c
int fib(int n){
    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }
  
    return fib(n - 1) + fib(n - 2);
}
```


### Recursion + memorization (Top-Down)

```c
int fib_arr(int n, int *arr)
{
    if (n < 2) {
        return arr[n];
    }
  
    arr[n] = fib_arr(n - 1, arr) + fib_arr(n - 2, arr);
  
    return arr[n];
}


int fib(int n){
  
    int dp[n + 2];
    memset(dp, 0, sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
  
    int res = fib_arr(n, dp);
    return res;
}
```

### Array (Bottom-Up)

```c
int fib(int n){
    int dp[n + 2];
    dp[0] = 0;
    dp[1] = 1;
  
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
  
    return dp[n];
}
```
